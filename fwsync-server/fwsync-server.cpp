
#include "fwsync-server.h"

namespace fwsync
{
	void Server::listen(int iPort)
	{
		ServerSocket serverSocket(iPort);
		
		cout << "FWSync Server listening...\r\n";
		
		while (Socket* socket = serverSocket.accept())
		{
			cout << "Incoming Client\r\n";

			this->handle(socket);

			delete socket;

			cout << "Listening again...\r\n";
		}
	}

	void Server::handle(Socket *socket)
	{
		char line[MAXPATH + 1];

		cout << "Connected!\r\n";

		// say hello to client
		socket->write("Hello FWSync_0.1\r\n");


		// read first line of request
		while (socket->readline(line, MAXPATH) > 0)
		{
			vector<string> params = *new vector<string>();
			cout << line << "\r\n";

			strsplit(line, params);

			if (params.size() > 0)
				for (int i = 0; i < params[0].length(); i++)
					params[0][i] = tolower(params[0][i]);

			// echo request to terminal
			cout << "Got request: " << params[0] << "\r\n";

			CommandHandler* pCommand = CommandFactory::create(params[0]);

			if (pCommand != NULL)
			{
				pCommand->process(socket, params);
			}
			else
				socket->writeline("Unknown command");
		}
	}

}