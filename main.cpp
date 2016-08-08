#include <iostream>
using namespace std;

#include "TCPServer.h"
#include "TCPClientFacade.h"
#include "TCPServerFacade.h"
#include "LinuxSocket.h"

#define PORT 6677

int main() {
    chdir("/home/zpb/ClionProjects/FileTransport");

	if(fork()>0)
	{
		usleep(1000);
		TCPClientFacade client;
		client.connectTo("127.0.0.1",PORT);
		client.recvFile("2.txt");
	}
	else{


		TCPServerFacade f;
		f.waitConnect(PORT);
	}






    return 0;
}