//
// Created by zpb on 16-8-3.
//

#ifndef FILETRANSPORT_TCPCONNECTION_H
#define FILETRANSPORT_TCPCONNECTION_H

#include <string>
#include "TCPServerState.h"

class TCPConnection {
public:
    TCPConnection(int serverSocket);
    void setClient(std::string clientIp,int clientPort);
    int sendTo(std::string file);
    int recvFrom(std::string file);
    void closeConnection();

    void createThread();

#if defined __LINUX__
    static void *newThread(void *arg);
#elif defined __WINDOWS__
	static unsigned int newThread(void *arg);
#endif

private:
    int _serverSocket;
    std::string _clientIp;
    int _clientPort;

    unsigned long _threadID;
    std::string _file;

    TCPServerState *_state;
};


#endif //FILETRANSPORT_TCPCONNECTION_H
