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

	void GetCommandHandler::process(Socket* socket, vector<string>& params)
	{
		if (params.size() < 2)
		{
			socket->writeline("-1");
			throw("Syntax error");
		}
		FileReader* fr = new FileReader(params[1]);

		fr->writeToSocket(socket);

		cout << endl;

		delete fr;
	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}
