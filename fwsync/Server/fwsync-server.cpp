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
		socket->write("FWSync server running on ");
		socket->writeline(OSRUNNING);
		socket->write("\n");


		// read first line of request
		try
		{
			while (socket->readline(line, MAXPATH) > 0)
			{
				vector<string> params = *new vector<string>();

				cout << line << "\n";

				strsplit(line, params, ' ');

				if (params.size() > 0)
				{
					for (int i = 0; i < params[0].length(); i++)
						params[0][i] = tolower(params[0][i]);

					// echo request to terminal
					cout << "Got request: " << params[0].c_str() << endl;

					CommandHandler* pCommand = CommandFactory::create(params[0]);

					if (pCommand != NULL)
					{
						try
						{
							pCommand->process(socket, params);
						}
						catch (const char* ex)
						{
							socket->writeline(ex);
							socket->writeline("");
						}
						catch (SocketException& ex)
						{
							cout << endl << "Socket error occured" << endl;
							socket->close();
						}
					}
					else
						socket->writeline("Unknown command\n");

					delete pCommand;
				}
				else
					socket->writeline("Syntax error\n");
			}
		}
		catch (SocketException& ex)
		{
			cout << "Socket exception occured" << endl;
		}
	}
}