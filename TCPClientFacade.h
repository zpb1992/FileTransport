//
// Created by zpb on 16-8-3.
//

#ifndef FILETRANSPORT_TCPCLIENTFACADE_H
#define FILETRANSPORT_TCPCLIENTFACADE_H

#include <string>
#include "TCPClient.h"

class TCPClientFacade {
public:
    TCPClientFacade();
    void connectTo(std::string ip,unsigned short port);
    void sendFile(std::string file);
    void recvFile(std::string file);
    void closeConnection();

private:
    TCPClient *_client;
};


#endif //FILETRANSPORT_TCPCLIENTFACADE_H
