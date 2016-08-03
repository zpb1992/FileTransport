//
// Created by zpb on 16-8-1.
//

#ifndef FILETRANSPORT_TCPCLIENT_H
#define FILETRANSPORT_TCPCLIENT_H

#include <string>
#include <netinet/in.h>
#include "TCPClientState.h"


class TCPClient {
public:
    TCPClient();
    void createSocket(int domain,int type,int protocol);
    void connect(std::string ip,int port);
    void send(std::string file);
    void recv(std::string file);
    void closeSocket();


private:
    int _domain;
    int _type;
    int _protocol;
    int _socket;
    std::string _serverStringAddr;
    int _serverPort;

    TCPClientState *_state;

};


#endif //FILETRANSPORT_TCPCLIENT_H
