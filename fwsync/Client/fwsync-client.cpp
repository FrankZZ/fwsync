#include "fwsync-client.h"

using namespace std;

namespace fwsync
{
	Client::Client()
	{

	}

	Client::~Client()
	{
		/*
		socket->close();
		delete socket;
		*/
	};

	void Client::connect(const char* szIp, int iPort)
	{
		Socket* socket = NULL;
		
		try
		{
			socket = new ClientSocket(szIp, iPort);
		}
		catch (runtime_error& ex)
		{
			delete socket;
			throw(ex);
		}

		ReadFromSocket(socket); //Read welcome message

		string szLine;

		while (getline(cin, szLine))
		{
			if (szLine.size() == 0)
				continue;

			socket->writeline(szLine.c_str());

			vector<string> params = vector<string>();

			strsplit(szLine, params, ' ');

			if (params.size() > 0)
			{

				for (int i = 0; i < params[0].length(); i++)
					params[0][i] = tolower(params[0][i]);

				CommandHandler* pCommand = CommandFactory::create(params[0]);

				if (pCommand != NULL)
				{
					try
					{
						pCommand->process(socket, params);
					}
					catch (const char* ex)
					{
						cout << ex << endl;
					}
				}
				else
					CommandFactory::create("DEFAULT")->process(socket, params);

				delete pCommand;
			}
			
		}

		delete socket;
	}

	void Client::ReadFromSocket(Socket* socket)
	{
		char line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH) > 0)
		{
			//vector<string> params = *new vector<string>();
			cout << line << "\n";
		}
	}
}