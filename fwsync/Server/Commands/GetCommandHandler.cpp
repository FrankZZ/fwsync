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

		if (params.size() < 3)
		{
			socket->writeline("-1");
			throw("Syntax error");
		}

		FileReader* fr = new FileReader(params[1]);
		
		socket->writeline("OK");

		fr->writeToSocket(socket);

		cout << endl;

		delete fr;

		socket->writeline("");
	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}
