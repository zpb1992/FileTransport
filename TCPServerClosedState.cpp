//
// Created by zpb on 16-8-3.
//

#include "TCPServerClosedState.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>

int TCPServerClosedState::createSocket(int domain, int type, int protocol) {
    return socket(domain,type,protocol);
}


int TCPServerClosedState::receiveFrom(int socket, std::string file) {
    std::cout<<"server is closed,can not recv"<<std::endl;
    return 0;
}

int TCPServerClosedState::sendTo(int socket, std::string file) {
    std::cout<<"server is closed,can not send"<<std::endl;
    return 0;
}

int TCPServerClosedState::closeSocket(int socket) {
    std::cout<<"server is closed,can not close"<<std::endl;
    return 0;
}

int TCPServerClosedState::bindTo(int socket, std::string ip, int port, int domain) {
    struct sockaddr_in addr;
    if(domain==AF_INET) {
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        addr.sin_addr.s_addr = inet_addr(ip.c_str());
    }
    bind(socket, (sockaddr *) &addr, sizeof(addr));
    return 0;
}

int TCPServerClosedState::lisenTo(int socket, int backlog) {
    return listen(socket,backlog);
}

int TCPServerClosedState::acceptConnect(int socket,std::string &addr,int &port)
{
    std::cout<<"server is closed,can not accept"<<std::endl;
    return -1;
}
