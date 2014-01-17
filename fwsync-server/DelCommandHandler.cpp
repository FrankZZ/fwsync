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
		if (_wremove(params[1].c_str()) != 0)
			throw(L"Cannot delete file");
		else
			socket->writeline("File deleted.\n");
	}

	CommandHandler* DelCommandHandler::clone()
	{
		return new DelCommandHandler();
	}

}