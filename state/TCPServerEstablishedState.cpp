//
// Created by zpb on 16-8-3.
//

#include <iostream>
#include "TCPServerEstablishedState.h"

int TCPServerEstablishedState::createSocket(int domain, int type, int protocol) {
    std::cout<<"server is established,can not create socket"<<std::endl;
    return 0;
}

int TCPServerEstablishedState::bindTo(int socket, std::string ip, unsigned short port, int domain) {
    std::cout<<"server is established,can not bind"<<std::endl;
    return 0;
}

int TCPServerEstablishedState::lisenTo(int socket, int backlog) {
    std::cout<<"server is established,can not listen"<<std::endl;
    return 0;
}

int TCPServerEstablishedState::acceptConnect(int socket,std::string &addr,unsigned short &port) {
    std::cout<<"server is established,can not accept"<<std::endl;
    return 0;
}

int TCPServerEstablishedState::receiveFrom(int socket, std::string file) {
    recvFile(socket,file);
    return 0;
}

int TCPServerEstablishedState::sendTo(int socket, std::string file) {
    sendFile(socket,file);
    return 0;
}

int TCPServerEstablishedState::closeSocket(int socket) {
    _platform->closeSocket(socket);
    return 0;
}













