#include "RenCommandHandler.h"

using namespace std;

namespace fwsync
{

	RenCommandHandler RenCommandHandler::m_renCmdHandler(string("ren"));

	RenCommandHandler::RenCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	RenCommandHandler::RenCommandHandler()
	{

	}

	void RenCommandHandler::process(Socket* socket, vector<string>& params)
	{
		if (params.size() < 3)
		{
			socket->writeline("-1");
			throw("Syntax error");
		}

		/*
		if (rename(params[1].c_str(), params[2].c_str()) == 0)
			socket->writeline("File renamed.");
		else
			throw("Cannot rename file.");
		
		socket->writeline("");
		*/
		throw("RENAMING A FILE IS DISABLED");
	}

	CommandHandler* RenCommandHandler::clone()
	{
		return new RenCommandHandler();
	}
}
