#include "GetCommandHandler.h"

using namespace std;

namespace fwsync
{

	GetCommandHandler GetCommandHandler::m_getCmdHandler(string("get"));

	GetCommandHandler::GetCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	GetCommandHandler::GetCommandHandler()
	{

	}

	void GetCommandHandler::process(Socket* socket, string szLine)
	{
		vector<string> params = vector<string>();
		strsplit(szLine, params, ' ', 3);

		if (params.size() != 3)
			throw("SYNTAX: GET [remote file] [local file]");
		
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
		
		Directory::createSubDirectories(params[2], true);

		FileWriter* fw = new FileWriter(params[2]);

		fw->readFromSocket(socket);

		delete fw;

		while (socket->readline(line, MAXPATH) > 0)
		{
			cout << line << endl;
		}

	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}