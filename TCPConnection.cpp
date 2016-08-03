//
// Created by zpb on 16-8-3.
//

#include "TCPConnection.h"
#include "TCPServerEstablishedState.h"

TCPConnection::TCPConnection(int serverSocket) {
    _serverSocket=serverSocket;
    _state=new TCPServerEstablishedState();

}

int TCPConnection::sendTo(std::string file) {
    _state->sendTo(_serverSocket,file);
    return 0;
}

int TCPConnection::recvFrom(std::string file) {
    _state->receiveFrom(_serverSocket,file);
    return 0;
}

void TCPConnection::setClient(std::string clientIp, int clientPort) {
    _clientIp=clientIp;
    _clientPort=clientPort;
}

void TCPConnection::closeConnection() {
    _state->closeSocket(_serverSocket);
}

void *TCPConnection::newThread(void *arg) {
    // TO DO
    //_thisObj->sendTo(_thisObj->_file);

    return nullptr;
}

void TCPConnection::createThread() {
    pthread_create(&_threadID, nullptr,newThread,nullptr);
}




