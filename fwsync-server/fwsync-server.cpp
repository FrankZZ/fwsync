#include "fwsync-server.h"

namespace fwsync
{
	void Server::listen(int iPort)
	{
		ServerSocket serverSocket(iPort);
		
		wcout << "FWSync Server listening...\r\n";
		
		while (Socket* socket = serverSocket.accept())
		{
			wcout << "Incoming Client\r\n";

			this->handle(socket);

			delete socket;

			cout << "Listening again...\r\n";
		}
	}

	void Server::handle(Socket *socket)
	{
		wchar_t line[MAXPATH + 1];

		wcout << "Connected!\r\n";

		// say hello to client
		socket->write(L"FWSync server running on ");
		socket->writeline(OSRUNNING);
		socket->write(L"\n");


		// read first line of request
		try
		{
			while (socket->readline(line, MAXPATH) > 0)
			{
				vector<wstring> params = *new vector<wstring>();

				wcout << line << "\n";

				wstrsplit(line, params, L' ');

				if (params.size() > 0)
				{
					for (int i = 0; i < params[0].length(); i++)
						params[0][i] = tolower(params[0][i]);

					// echo request to terminal
					wcout << "Got request: " << params[0].c_str() << endl;

					CommandHandler* pCommand = CommandFactory::create(params[0]);

					if (pCommand != NULL)
					{
						try
						{
							pCommand->process(socket, params);
						}
						catch (const wchar_t* ex)
						{
							socket->writeline(ex);
							socket->writeline(L"");
						}
						catch (SocketException& ex)
						{
							wcout << endl << "Socket error occured" << endl;
							socket->close();
						}
					}
					else
						socket->writeline(L"Unknown command\n");

					delete pCommand;
				}
				else
					socket->writeline(L"Syntax error\n");
			}
		}
		catch (SocketException& ex)
		{
			cout << "Socket exception occured" << endl;
		}
	}
}