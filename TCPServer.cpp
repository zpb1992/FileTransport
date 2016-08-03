//
// Created by zpb on 16-8-3.
//

#include "TCPServer.h"
#include "TCPServerClosedState.h"
#include "TCPServerEstablishedState.h"
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
    _state->bindTo(_listenSocket,_serverStringAddr,_serverPort,_domain);
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
        _connection.push_back(TCPConnection(conectedSocket));
    }

}


void TCPServer::close() {

}

TCPServer::TCPServer() {
    _state=new TCPServerClosedState();
}















