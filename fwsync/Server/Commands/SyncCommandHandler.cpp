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

	void SyncCommandHandler::process(Socket* socket, string szLine)
	{
		vector<string> params = vector<string>();
		strsplit(szLine, params, ' ', 3);

		if (params.size() != 3)
			throw("SYNTAX: SYNC [local dir] [remote dir]");

		if (Directory::isDir(params[2]))
		{
			socket->writeline("OK");
		}
	}

	CommandHandler* SyncCommandHandler::clone()
	{
		return new SyncCommandHandler();
	}
}