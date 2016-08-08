//
// Created by zpb on 16-8-4.
//

#include "LinuxSocket.h"

#ifdef __LINUX__



int LinuxSocket::init() {
    return 0;
}

int LinuxSocket::createSocket(int domain, int type, int protocol) {
    int result=socket(domain,type,protocol);
    if(result<0)
    {
        std::cout<<"linux socket create failed"<<std::endl;
        return -1;
    }
    return result;
}

int LinuxSocket::connectTo(int socket, short family,std::string ip,unsigned short port) {
    int result=-1;
    if(family==AF_INET)
    {
        struct sockaddr_in sock_in;
        sock_in.sin_family=family;
        sock_in.sin_port=hostToNet16(port);
        sock_in.sin_addr.s_addr=inet_addr(ip.c_str());
        result=connect(socket,(sockaddr *)&sock_in,sizeof(sockaddr_in));
    }

    if(result==-1)
    {
        std::cout<<"linux socket connect failed"<<std::endl;
        return -1;
    }
    return result;
}

int LinuxSocket::bindTo(int socket, short family,std::string ip,unsigned short port) {

    int result=-1;
    if(family==AF_INET)
    {
        struct sockaddr_in sock_in;
        sock_in.sin_family=family;
        sock_in.sin_port=hostToNet16(port);
        sock_in.sin_addr.s_addr=inet_addr(ip.c_str());

        result=bind(socket,(sockaddr *)&sock_in,sizeof(sockaddr_in));
    }

    if(result==-1)
    {
        std::cout<<"linux socket bind failed"<<std::endl;
        return -1;
    }
    return result;
}

int LinuxSocket::listenOn(int socket, int backlog) {
    if(listen(socket,backlog)==-1)
    {
        std::cout<<"linux socket listend failed"<<std::endl;
        return -1;
    }
    return 0;
}

int LinuxSocket::acceptFrom(int socket, int family,std::string &ip,unsigned short &port) {
    int result=-1;
    if(family==AF_INET)
    {
        struct sockaddr_in sock_in;
        int sockLen;
        sock_in.sin_family=family;
        sock_in.sin_port=hostToNet16(port);
        sock_in.sin_addr.s_addr=inet_addr(ip.c_str());

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

int LinuxSocket::sendTo(int socket, void *buffer, int len, int flags) {
    int sendLen=send(socket,buffer,len,flags);
    if(sendLen<0)
    {
        std::cout<<"linux socket send failed"<<std::endl;
        return -1;
    }
    return sendLen;
}

int LinuxSocket::recvFrom(int socket, void *buffer, int len, int flags) {
    int recvLen=recv(socket,buffer,len,flags);
    if(recvLen<0)
    {
        std::cout<<"linux socket recv failed"<<std::endl;
        return -1;
    }
    return recvLen;
}

int LinuxSocket::closeSocket(int socket) {
    if(close(socket)==-1)
    {
        std::cout<<"linux close socket failed"<<std::endl;
        return -1;
    }
    return 0;
}

int LinuxSocket::cleanup() {
    return 0;
}

unsigned short LinuxSocket::hostToNet16(unsigned short num){
    return htons(num);
}

unsigned LinuxSocket::hostToNet32(unsigned num){
    return htonl(num);
}

unsigned short LinuxSocket::netToHost16(unsigned short num)  {
    return ntohs(num);
}

unsigned LinuxSocket::netToHost32(unsigned num) {
    return ntohl(num);
}

unsigned LinuxSocket::getAddrNum(const char *ip){
    return inet_addr(ip);
}

std::string LinuxSocket::getAddrStr(unsigned int in) {
    in_addr temp;
    temp.s_addr=in;
    return inet_ntoa(temp);
}

#endif
