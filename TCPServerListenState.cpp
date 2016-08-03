//
// Created by zpb on 16-8-3.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include "TCPServerListenState.h"

int TCPServerListenState::createSocket(int domain, int type, int protocol) {
    std::cout<<"server is Listend,can not create socket"<<std::endl;

    return 0;
}

int TCPServerListenState::bindTo(int socket, std::string ip, int port, int domain) {
    std::cout<<"server is Listend,can not bind"<<std::endl;
    return 0;
}

int TCPServerListenState::lisenTo(int socket, int backlog) {
    std::cout<<"server is Listend,can not listen "<<std::endl;
    return 0;
}

int TCPServerListenState::acceptConnect(int socket,std::string &addr,int &port)
{
    sockaddr_in peerAddr;
    int addrLen;
    accept(socket, (sockaddr *) &peerAddr, (socklen_t *) &addrLen);
    addr=inet_ntoa(peerAddr.sin_addr);
    port=ntohs(peerAddr.sin_port);

    return 0;
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













