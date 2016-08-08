//
// Created by zpb on 16-8-3.
//

#include "TCPServerClosedState.h"

int TCPServerClosedState::createSocket(int domain, int type, int protocol) {
    return _platform->createSocket(domain,type,protocol);
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

int TCPServerClosedState::bindTo(int socket, std::string ip, unsigned short port, int domain) {
    return _platform->bindTo(socket,domain,ip,port);
}

int TCPServerClosedState::lisenTo(int socket, int backlog) {
    return _platform->listenOn(socket,backlog);
}

int TCPServerClosedState::acceptConnect(int socket,std::string &addr, unsigned short &port)
{
    std::cout<<"server is closed,can not accept"<<std::endl;
    return -1;
}
