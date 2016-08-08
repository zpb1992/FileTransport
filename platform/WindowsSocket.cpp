//
// Created by zpb on 16-8-4.
//

#include "PlatformSocket.h"

#ifdef __WINDOWS__

#include "WindowsSocket.h"

#pragma comment(lib,"ws2_32.lib")

int WindowsSocket::init() {
	WSADATA Ws;
    if(WSAStartup(MAKEWORD(2,2),&Ws)!=0)
    {
        std::cout<<"init windows socket failed"<<std::endl;
        return -1;
    }
    return 0;
}

int WindowsSocket::createSocket(int domain, int type, int protocol) {
    int sock=socket(domain,type,protocol);
    if(sock==INVALID_SOCKET)
    {
        std::cout<<"windows create socket failed"<<std::endl;
        return -1;
    }
    return sock;
}

int WindowsSocket::connectTo(int socket, short family,std::string ip,unsigned short port) {
	int result=-1;
	if(family==AF_INET)
	{
		struct sockaddr_in sock_in;
		sock_in.sin_family=family;
		sock_in.sin_port=hostToNet16(port);
		sock_in.sin_addr.S_un.S_addr=inet_addr(ip.c_str());
		result=connect(socket,(sockaddr *)&sock_in,sizeof(sockaddr_in));
	}

	if(result==-1)
	{
		std::cout<<"windows socket connect failed"<<std::endl;
		return -1;
	}
	return result;
}

int WindowsSocket::bindTo(int socket, short family,std::string ip,unsigned short port) {
	int result=-1;
	if(family==AF_INET)
	{
		struct sockaddr_in sock_in;
		sock_in.sin_family=family;
		sock_in.sin_port=hostToNet16(port);
		sock_in.sin_addr.S_un.S_addr=inet_addr(ip.c_str());

		result=bind(socket,(sockaddr *)&sock_in,sizeof(sockaddr_in));
	}

	if(result==-1)
	{
		std::cout<<"windows socket bind failed"<<std::endl;
		return -1;
	}
	return result;
}

int WindowsSocket::listenOn(int socket, int backlog) {
    int result=listen(socket,backlog);
    if(result!=0)
    {
        std::cout<<"windows socket listen failed"<<std::endl;
        return -1;
    }
    return 0;
}

int WindowsSocket::acceptFrom(int socket, int family,std::string &ip,unsigned short &port) {
	int result=-1;
	if(family==AF_INET)
	{
		struct sockaddr_in sock_in;
		int sockLen=sizeof(sock_in);

		result=accept(socket,(sockaddr *)&sock_in,(socklen_t *)&sockLen);
		ip=inet_ntoa(sock_in.sin_addr);
		port=ntohs(sock_in.sin_port);
	}

	if(result==-1)
	{
		std::cout<<"linux socket accept failed"<<std::endl;
		return -1;
	}
	return result;
}

int WindowsSocket::sendTo(int socket, void *buffer, int len, int flags) {
    int result=send(socket,(const char *)buffer,len,flags);
    if(result==SOCKET_ERROR)
    {
        std::cout<<"windows socket send failed"<<std::endl;
        return -1;
    }
    return 0;
}

int WindowsSocket::recvFrom(int socket, void *buffer, int len, int flags) {
	int result = recv(socket, (char *)buffer, len, flags);
    if(result==0||result==SOCKET_ERROR)
    {
        std::cout<<"client exit"<<std::endl;
        return -1;
    }
    return result;
}

int WindowsSocket::closeSocket(int socket) {
    int result=closesocket(socket);
    if(result!=0)
    {
        std::cout<<"windows close socket failed"<<std::endl;
        return -1;
    }
    return 0;
}

int WindowsSocket::cleanup(){
    int result=WSACleanup();
    if(result==SOCKET_ERROR)
    {
        std::cout<<"windows cleanup failed"<<std::endl;
        return -1;
    }
    return 0;
}

unsigned short WindowsSocket::hostToNet16(unsigned short num){
    return htons(num);
}

unsigned WindowsSocket::hostToNet32(unsigned num){
    return htonl(num);
}

unsigned short WindowsSocket::netToHost16(unsigned short num)  {
    return ntohs(num);
}

unsigned WindowsSocket::netToHost32(unsigned num) {
    return ntohl(num);
}

unsigned WindowsSocket::getAddrNum(const char *ip){
	unsigned result;
	if (inet_pton(AF_INET, ip, &result) < 0)
	{
		std::cout << "windows socket inet_pton failed" << std::endl;
		return -1;
	}
	return result;
}

std::string WindowsSocket::getAddrStr(unsigned in) {
	in_addr temp;
	temp.S_un.S_addr=in;

	char result[20];
	if (inet_ntop(AF_INET, &temp.S_un.S_addr, result, sizeof(result)) == nullptr)
	{
		std::cout << "windows socket inet_ntop failed" << std::endl;
		return "";
	}
	return std::string(result);
}
#endif
