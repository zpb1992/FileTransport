//
// Created by zpb on 16-8-3.
//

#include <iostream>
#include "TCPServer.h"
#include "TCPServerClosedState.h"
#include "TCPServerListenState.h"

void TCPServer::createSocket(int domain, int type, int protocol) {
    _domain=domain;
    _type=type;
    _protocol=protocol;
    _listenSocket=_state->createSocket(_domain,_type,_protocol);
}

void TCPServer::bindAddr(std::string ip, int port) {
    _serverStringAddr=ip;
    _serverPort=port;
    if(_state->bindTo(_listenSocket,_serverStringAddr,_serverPort,_domain)!=0)
    {
        std::cout<<"Server bind error"<<std::endl;
        exit(1);
    }
}

void TCPServer::listenTo(int backlog) {
    _backlog=backlog;
    _state->lisenTo(_listenSocket,_backlog);
    _state=new TCPServerListenState();
}

void TCPServer::acceptConnection() {
    std::string clientIp;
    int clientPort;
    while(1)
    {
        int conectedSocket=_state->acceptConnect(_listenSocket,clientIp,clientPort);
        TCPConnection *connection=new TCPConnection(conectedSocket);
        connection->createThread();
        _connections.push_back(connection);
    }

}


void TCPServer::close() {
    delete _state;
    _state=nullptr;
    for(int i=0;i<_connections.size();++i)
        delete _connections[i];
    _connections.clear();
}

TCPServer::TCPServer() {
    _state=new TCPServerClosedState();
}















