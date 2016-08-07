//
// Created by zpb on 16-8-3.
//
#include "TCPServerListenState.h"

int TCPServerListenState::createSocket(int domain, int type, int protocol) {
    std::cout<<"server is Listend,can not create socket"<<std::endl;

    return 0;
}

int TCPServerListenState::bindTo(int socket, std::string ip, unsigned short port, int domain) {
    std::cout<<"server is Listend,can not bind"<<std::endl;
    return 0;
}

int TCPServerListenState::lisenTo(int socket, int backlog) {
    std::cout<<"server is Listend,can not listen "<<std::endl;
    return 0;
}

int TCPServerListenState::acceptConnect(int socket,std::string &addr,unsigned short &port)
{
    sockaddr_in peerAddr;
    int addrLen;
    int conectedSocket=_platform->acceptFrom(socket, AF_INET,addr,port);
    addr=_platform->getAddrStr(peerAddr.sin_addr.s_addr);
    port=_platform->netToHost16(peerAddr.sin_port);

    return conectedSocket;
}

int TCPServerListenState::receiveFrom(int socket, std::string file) {
    std::cout<<"server is Listend,can not recv"<<std::endl;
    return 0;
}

int TCPServerListenState::sendTo(int socket, std::string file) {
    std::cout<<"server is Listend,can not send"<<std::endl;
    return 0;
}

int TCPServerListenState::closeSocket(int socket) {
    close(socket);
    return 0;
}













