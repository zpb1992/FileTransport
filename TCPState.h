//
// Created by zpb on 16-7-29.
//

#ifndef FILETRANSPORT_TCPSTATE_H
#define FILETRANSPORT_TCPSTATE_H

#include "PlatformSocket.h"
#include <fstream>
#include "LinuxSocket.h"
#include "WindowsSocket.h"

#define BUFFER_MAX 1000


class TCPState {
protected:
    ssize_t recvFrom(int socket, void *data, int len);

    ssize_t sendTo(int socket, void *data, int len);

    int sendFile(int socket, std::string file);

    int recvFile(int socket,std::string file);

protected:
    uint32_t getFileLength(std::ifstream &ifs);
    long long getFileLength(std::ofstream &ofs);

    void numToChar(long long num,char *buffer,int len);
    long long charToNum(char *buffer, int len);

    uint32_t recvUint32(int socket);

protected:
    static PlatformSocket *_platform;
};


#endif //FILETRANSPORT_TCPSTATE_H
