#include "PutCommandHandler.h"

using namespace std;

namespace fwsync
{

	PutCommandHandler PutCommandHandler::m_putCmdHandler(string("put"));

	PutCommandHandler::PutCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	PutCommandHandler::PutCommandHandler()
	{

	}

	void PutCommandHandler::process(Socket* socket, string szLine)
	{
		vector<string> params = vector<string>();
		strsplit(szLine, params, ' ', 3);

		if (params.size() != 3)
			throw("SYNTAX: PUT [local file] [remote file]");
		
		socket->writeline(szLine);
		char line[MAXPATH + 1];
		
		socket->readline(line, MAXPATH);

		if (strcmp(line, "OK") != 0)
		{
			while (socket->readline(line, MAXPATH) > 0)
			{
				cout << line << endl;
			}
			throw("Aborted");
		}

		FileReader* fw = new FileReader(params[2]);

		fw->writeToSocket(socket);

		delete fw;

		while (socket->readline(line, MAXPATH) > 0)
		{
			cout << line << endl;
		}
	}

	void interrupt(int param)
	{
		remove("test.exe");
	}

	CommandHandler* PutCommandHandler::clone()
	{
		return new PutCommandHandler();
	}
}