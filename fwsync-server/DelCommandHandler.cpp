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
		if (remove(params[1].c_str()) != 0)
			throw("Cannot delete file");
		else
			socket->writeline("File deleted.\n");
	}

	CommandHandler* DelCommandHandler::clone()
	{
		return new DelCommandHandler();
	}

}