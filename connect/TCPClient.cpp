//
// Created by zpb on 16-8-1.
//

#include "TCPClient.h"
#include "TCPClientClosedState.h"
#include "TCPClientEstablishedState.h"

void TCPClient::init()
{
	_state->init();
}

void TCPClient::createSocket(int domain, int type, int protocol) {
    _domain=domain;
    _type=type;
    _protocol=protocol;

    _socket = _state->createSocket(_domain, _type, _protocol);
    if(_socket<0)
    {
        std::cout<<"Client create socket error"<<std::endl;
        exit(1);
    }

}

void TCPClient::connect(std::string ip, int port) {
    _serverStringAddr=ip;
    _serverPort=port;

    if(_state->connectTo(_socket,_serverStringAddr,_serverPort,_domain)!=0)
    {
        std::cout<<"Client connect error"<<std::endl;
        exit(1);
    }


    _state=new TCPClientEstablishedState();

}


void TCPClient::closeSocket() {
    _state->closeSocket(_socket);
}

void TCPClient::send(std::string file) {
    if(_state->sendTo(_socket,file)<0)
    {
        std::cout<<"Client send error"<<std::endl;
        exit(1);
    }
}

void TCPClient::recv(std::string file) {
    if(_state->receiveFrom(_socket,file)<0)
    {
        std::cout<<"Client recv error"<<std::endl;
        exit(1);
    }
}

void TCPClient::cleanup()
{
	_state->cleanup();
}

TCPClient::TCPClient() {
    _state=new TCPClientClosedState();
}





