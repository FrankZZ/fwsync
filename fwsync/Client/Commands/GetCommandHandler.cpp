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
		if (params.size() != 3)
			throw("SYNTAX: GET [remote file] [local file]");
		

		FileWriter* fw = new FileWriter(params[2]);

		fw->readFromSocket(socket);

		delete fw;

	}

	CommandHandler* GetCommandHandler::clone()
	{
		return new GetCommandHandler();
	}
}