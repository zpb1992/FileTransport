//
// Created by zpb on 16-8-3.
//

#include "TCPConnection.h"
#include "TCPServerEstablishedState.h"
#include "PlatformThread.h"
#include "WindowsThread.h"
#include "LinuxThread.h"

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

#if defined __LINUX__
void *TCPConnection::newThread(void *arg) {
    // TO DO
    TCPConnection *_thisObj=(TCPConnection *)arg;

    _thisObj->sendTo("1.txt");
    return nullptr;
}
#elif defined __WINDOWS__
unsigned int TCPConnection::newThread(void *arg) {
	// TO DO
	TCPConnection *_thisObj=(TCPConnection *)arg;

		_thisObj->sendTo("1.txt");
	return 0;
}
#endif


void TCPConnection::createThread() {
    PlatformThread *thread;
#if defined(__LINUX__)
    thread=new LinuxThread();
#elif defined(__WINDOWS__)
    thread=new WindowsThread();
#endif
    thread->createNewThread((PlatformThread::threadFunc)*newThread, this);
	_threadID=thread->getThreadID();

}




