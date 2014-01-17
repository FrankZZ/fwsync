#include "DelCommandHandler.h"

using namespace std;

namespace fwsync
{

	DelCommandHandler DelCommandHandler::m_delCmdHandler(wstring(L"del"));

	DelCommandHandler::DelCommandHandler(wstring sCommand) : CommandHandler(sCommand)
	{

	}

	DelCommandHandler::DelCommandHandler()
	{

	}

	void DelCommandHandler::process(Socket* socket, vector<wstring>& params)
	{
		wcout << "Writing dirlisting\n";
		socket->writeline(Directory::getListing(params[1]).c_str());
		wcout << "Wrote dirlisting\n";
		socket->writeline(L"");
	}

	CommandHandler* DelCommandHandler::clone()
	{
		return new DelCommandHandler();
	}

}