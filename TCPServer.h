//
// Created by zpb on 16-8-3.
//

#ifndef FILETRANSPORT_TCPSERVER_H
#define FILETRANSPORT_TCPSERVER_H


#include <string>
#include "TCPServerState.h"
#include "TCPConnection.h"


class TCPServer {
public:
    TCPServer();
    void createSocket(int domain,int type,int protocol);
    void bindAddr(std::string ip,int port);
    void listenTo(int backlog);
    void acceptConnection();
    //void read(int index,std::string file);
    //void write(int index,std::string file);
    void close();

private:
    int _domain;
    int _type;
    int _protocol;
    int _listenSocket;
    int _backlog;
    std::string _serverStringAddr;
    int _serverPort;

    TCPConnection *_connection;

    TCPServerState *_state;
};


#endif //FILETRANSPORT_TCPSERVER_H
