#include <iostream>

using namespace std;

#include "TCPServer.h"
#include "TCPClient.h"
#define PORT 6677

int main() {
    /*TCPServer server;
    server.createSocket(AF_INET,SOCK_STREAM,0);
    server.bindAddr("0.0.0.0",PORT);
    server.listenTo(10);
    server.acceptConnection();*/

    TCPClient client;
    client.createSocket(AF_INET,SOCK_STREAM,0);
    client.connect("127.0.0.1",PORT);
    client.recv("recved.txt");
    return 0;
}