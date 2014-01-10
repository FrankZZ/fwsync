//=============================================================================
// A very basic tcp-server
// (c) 8-12-2010, Frans Spijkerman, Avans Hogeschool
//=============================================================================

// system modules
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// our own modules
#include "socket.h"

// constants
static const int MAXPATH = 256; // Maximale lengte van padnaam
static const int TCP_PORT = 1080;

void strsplit(string str, vector<string> &tokens)
{
	string buf;
	stringstream ss(str); // Insert the string into a stream

	//vector<string> tokens; // Create vector to hold our words

	while (ss >> buf)
		tokens.push_back(buf);
}

//=============================================================================
void handle(Socket *socket)
//=============================================================================
{
	char line[MAXPATH + 1];

	cout << "Connected!\r\n";

	// say hello to client
	socket->write("HELO JFSync_0.1\r\n");
	// read first line of request
	while (socket->readline(line, MAXPATH) > 0)
	{
		vector<string> params = *new vector<string>();
		
		strsplit(line, params);

		// echo request to terminal
		cout << "Got request: " << params[0] << "\r\n";
		
		if (params.size() > 0)
		{
			if (params[0] == "INFO")
			{
				time_t     now = time(0);
				struct tm  tstruct;
				char       buf[80];
				localtime_s(&tstruct, &now);
				
				strftime(buf, sizeof(buf), "%Y%m%d_%X", &tstruct);
				
				socket->write("JFSync Server 0.1a ");
				socket->writeline(buf);

				delete buf;
			}
			else if (params[0] == "QUIT")
			{
				socket->write("BYE\r\n");
				socket->close();
				delete socket;
				return;
			}
		}
		
		socket->write(line);
		socket->write(" OK\r\n");

		//delete params;
	}
	// close and delete socket (created by server's accept)
	delete socket;
}

//=============================================================================
// Example of a tcp-server
//=============================================================================
int main()
//=============================================================================
{
	// CREATE A SERVER SOCKET 
	ServerSocket serverSocket(TCP_PORT);
	// WAIT FOR CONNECTION FROM CLIENT; WILL CREATE NEW SOCKET
	cout << "Server listening\r\n";
	while (Socket *socket = serverSocket.accept())
	{
		// COMMUNICATE WITH CLIENT OVER NEW SOCKET
		handle(socket);
		cout << "Server listening again\r\n";
	}
	return 0;
}

