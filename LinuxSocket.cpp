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

int LinuxSocket::connectTo(int socket, const struct sockaddr *name, int namelen) {
    if(connect(socket,name,namelen)==-1)
    {
        std::cout<<"linux socket connect failed"<<std::endl;
        return -1;
    }
    return 0;
}

int LinuxSocket::bindTo(int socket, const struct sockaddr *addr, int addrlen) {
    if(bind(socket,addr,addrlen)==-1)
    {
        std::cout<<"linux socket bind failed"<<std::endl;
        return -1;
    }
    return 0;
}

int LinuxSocket::listenOn(int socket, int backlog) {
    if(listen(socket,backlog)==-1)
    {
        std::cout<<"linux socket listend failed"<<std::endl;
        return -1;
    }
    return 0;
}

int LinuxSocket::acceptFrom(int socket, struct sockaddr *addr, int *addrLen) {
    if(accept(socket,addr,(socklen_t *)addrLen)==-1)
    {
        std::cout<<"linux socket accept failed"<<std::endl;
        return -1;
    }
    return 0;
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
    in_addr addr;
    addr.s_addr=in;
    return inet_ntoa(addr);
}

#endif
