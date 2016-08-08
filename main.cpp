#include <iostream>

using namespace std;

#include "TCPServer.h"
#include "TCPClientFacade.h"
#include "TCPServerFacade.h"
#include "LinuxSocket.h"

#define PORT 6677

int main() {
            //usleep(1000);
            //TCPClientFacade client;
            //client.connectTo("127.0.0.1",PORT);
            //client.recvFile("2.txt");


	/*TCPServer server;
	server.init();
	server.createSocket(AF_INET,SOCK_STREAM,0);
	server.bindAddr("0.0.0.0",PORT);
	server.listenTo(10);
	server.acceptConnection();
	server.cleanup();*/
	TCPServerFacade f;
	f.waitConnect(PORT);

    return 0;
}