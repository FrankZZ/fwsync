#include "InfoCommandHandler.h"

using namespace std;

namespace fwsync
{

	InfoCommandHandler InfoCommandHandler::m_infoCmdHandler(wstring(L"info"));

	InfoCommandHandler::InfoCommandHandler(wstring sCommand) : CommandHandler(sCommand)
	{

	}

	InfoCommandHandler::InfoCommandHandler()
	{

	}

	void InfoCommandHandler::process(Socket* socket, vector<wstring>& params)
	{
		socket->writeline(L"FWSync Server 0.1a");
		socket->writeline(L"");
	}

	CommandHandler* InfoCommandHandler::clone()
	{
		return new InfoCommandHandler();
	}

}