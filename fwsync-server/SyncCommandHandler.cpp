#include "SyncCommandHandler.h"

using namespace std;

namespace fwsync
{

	SyncCommandHandler SyncCommandHandler::m_syncCmdHandler(wstring(L"sync"));

	SyncCommandHandler::SyncCommandHandler(wstring sCommand) : CommandHandler(sCommand)
	{

	}

	SyncCommandHandler::SyncCommandHandler()
	{

	}

	void SyncCommandHandler::process(Socket* socket, vector<wstring>& params)
	{
		
	}

	CommandHandler* SyncCommandHandler::clone()
	{
		return new SyncCommandHandler();
	}
}