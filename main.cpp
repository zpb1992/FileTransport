#include <iostream>
#include <unistd.h>

using namespace std;

#include "TCPServer.h"
#include "TCPClientFacade.h"
#include <unistd.h>
#define PORT 6677

int main() {

    std::cout<<get_current_dir_name()<<std::endl;
    chdir("/home/zpb/ClionProjects/FileTransport");
    std::cout<<get_current_dir_name()<<std::endl;

    int childProcessID=fork();
    if(childProcessID<0)
        return 0;
    else if(childProcessID>0)
    {
        usleep(1000);
        TCPClientFacade client;
        client.connectTo("127.0.0.1",PORT);
        client.recvFile("test2.txt");
    }
    else
    {
        TCPServer server;
        server.createSocket(AF_INET,SOCK_STREAM,0);
        server.bindAddr("0.0.0.0",PORT);
        server.listenTo(10);
        server.acceptConnection();
    }


    return 0;
}