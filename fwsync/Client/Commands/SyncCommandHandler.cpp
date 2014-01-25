#include "SyncCommandHandler.h"

using namespace std;

namespace fwsync
{

	SyncCommandHandler SyncCommandHandler::m_syncCmdHandler(string("sync"));

	SyncCommandHandler::SyncCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	SyncCommandHandler::SyncCommandHandler()
	{

	}

	void SyncCommandHandler::process(Socket* socket, vector<string>& params)
	{

	}

	CommandHandler* SyncCommandHandler::clone()
	{
		return new SyncCommandHandler();
	}
}