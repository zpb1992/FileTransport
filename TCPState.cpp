//
// Created by zpb on 16-7-29.
//

#include <cmath>
#include <sys/socket.h>
#include <cassert>
#include <netinet/in.h>
#include "TCPState.h"

ssize_t TCPState::recvFrom(int socket, void *data, int len) {
    return recv(socket,data,len,0);
}

ssize_t TCPState::sendTo(int socket, void *data, int len) {
    return send(socket, data, len, 0);
}

int TCPState::recvFile(int socket, std::string file) {
    std::ofstream ofs(file,std::ofstream::trunc);
    char *buffer=new char[BUFFER_MAX];

    uint32_t fileLen=recvUint32(socket);

    uint32_t recvedLen=0;
    while(recvedLen<fileLen)
    {
        uint32_t tempBufLen=BUFFER_MAX<(fileLen-recvedLen)?BUFFER_MAX:(fileLen-recvedLen);
        recvedLen+=recv(socket,buffer,tempBufLen,0);
    }


    return fileLen;
}

int TCPState::sendFile(int socket, std::string file) {
    std::ifstream ifs(file);
    uint32_t fileLen = htonl(getFileLength(ifs));
    char *buffer = new char[BUFFER_MAX];

    send(socket,&fileLen,sizeof(uint32_t),0);
    fileLen=htonl(fileLen);

    while (ifs)
    {
        ifs.read(buffer,BUFFER_MAX);
        long realReadLen=ifs.gcount();
        send(socket, buffer, (size_t) realReadLen, 0);
    }

    return fileLen;
}

uint32_t TCPState::getFileLength(std::ifstream &ifs) {
    uint32_t result;
    ifs.seekg(0, std::ios_base::end);
    result= (uint32_t) ifs.tellg();
    ifs.seekg(0,std::ios_base::beg);
    return result;
}

long long TCPState::getFileLength(std::ofstream &ofs) {
    long long result;
    ofs.seekp(0, std::ios_base::end);
    result=ofs.tellp();
    ofs.seekp(0,std::ios_base::beg);
    return result;
}

void TCPState::numToChar(long long num, char *buffer, int len) {
    int index=0;
    while(num!=0)
    {
        buffer[index]=num%256;
        num=num>>8;
        ++index;
    }
}

long long TCPState::charToNum(char *buffer, int len) {
    long long result=0;
    int index=0;
    while(index<len)
    {
        result+=buffer[index]*pow(256,index);
    }
    return result;
}

uint32_t TCPState::recvUint32(int socket) {
    uint32_t result;
    ssize_t recvLen=recv(socket,&result,sizeof(result),0);
    assert(recvLen==sizeof(result));
    return ntohl(result);
}









