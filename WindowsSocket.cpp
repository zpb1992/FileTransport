//
// Created by zpb on 16-8-4.
//
#ifdef __WINDOWS__

#include "WindowsSocket.h"
#include <iostream>
#include <winsock2.h>


int WindowsSocket::init() {
    if(WSAStartup(MAKEWORD(2,2),_Ws)!=0)
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

int WindowsSocket::connectTo(int socket, const struct sockaddr *name, int namelen) {
    int result=connect(socket,name,namelen);
    if(result==SOCKET_ERROR)
    {
        std::cout<<"windows socket connect failed"<<std::endl;
        return -1;
    }
    return 0;
}

int WindowsSocket::bindTo(int socket, const struct sockaddr *addr, int addrlen) {
    int result=bind(socket,addr,addrlen);
    if(result!=0)
    {
        std::cout<<"windows socket bind failed"<<std::endl;
        return -1;
    }
    return 0;
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

int WindowsSocket::acceptFrom(int socket, const struct sockaddr *addr, int *addrLen) {
    int connectSock=accept(socket,addr,addrLen);
    if(connectSock==INVALID_SOCKET)
    {
        std::cout<<"windows socket accept failed"<<std::endl;
        return -1;
    }
    return connectSock;
}

int WindowsSocket::sendTo(int socket, void *buffer, int len, int flags) {
    int result=send(socket,buffer,len,flags);
    if(result==SOCKET_ERROR)
    {
        std::cout<<"windows socket send failed"<<std::endl;
        return -1;
    }
    return 0;
}

int WindowsSocket::recvFrom(int socket, void *buffer, int len, int flags) {
    int result=recv(socket,buffer,len,flags);
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
    return inet_addr(ip.c_str());
}

const char *WindowsSocket::getAddrStr(unsigned int in) {
    return inet_ntoa(in_addr(in));
}
#endif