#include "InfoCommandHandler.h"

using namespace std;

namespace fwsync
{

	InfoCommandHandler InfoCommandHandler::m_infoCmdHandler(string("info"));

	InfoCommandHandler::InfoCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	InfoCommandHandler::InfoCommandHandler()
	{

	}

	void InfoCommandHandler::process(Socket* socket, string szLine)
	{
		socket->writeline("FWSync Server 0.1a");
		socket->writeline("");
	}

	CommandHandler* InfoCommandHandler::clone()
	{
		return new InfoCommandHandler();
	}

}