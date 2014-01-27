#include "DelCommandHandler.h"

using namespace std;

namespace fwsync
{

	DelCommandHandler DelCommandHandler::m_delCmdHandler(string("del"));

	DelCommandHandler::DelCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	DelCommandHandler::DelCommandHandler()
	{

	}

	void DelCommandHandler::process(Socket* socket, vector<string>& params)
	{
		/*
		if (remove(params[1].c_str()) != 0)
			throw("Cannot delete file.");
		socket->writeline("File deleted.");
		socket->writeline("");
		*/
		
		throw("DELETING A FILE IS DISABLED");
		
	}

	CommandHandler* DelCommandHandler::clone()
	{
		return new DelCommandHandler();
	}

}