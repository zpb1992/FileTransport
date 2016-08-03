//
// Created by zpb on 16-8-1.
//

#include "TCPClient.h"
#include <arpa/inet.h>
#include <string.h>
#include "TCPClientClosedState.h"
#include "TCPClientEstablishedState.h"
#include <unistd.h>

void TCPClient::createSocket(int domain, int type, int protocol) {
    _domain=domain;
    _type=type;
    _protocol=protocol;

    _socket = _state->createSocket(_domain, _type, _protocol);
}

void TCPClient::connect(std::string ip, int port) {
    _serverStringAddr=ip;
    _serverPort=port;

    _state->connectTo(_socket,_serverStringAddr,_serverPort,_domain);

    _state=new TCPClientEstablishedState();

}


void TCPClient::closeSocket() {
    _state->closeSocket(_socket);
}

void TCPClient::send(std::string file) {
    _state->sendTo(_socket,file);
}

void TCPClient::recv(std::string file) {
    _state->receiveFrom(_socket,file);
}

TCPClient::TCPClient() {
    _state=new TCPClientClosedState();
}





