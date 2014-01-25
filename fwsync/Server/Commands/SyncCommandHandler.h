#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include "../../Shared/Models/socket.h"
#include "time.h"

using namespace std;

namespace fwsync
{

	class SyncCommandHandler : public CommandHandler
	{
	private:
		SyncCommandHandler();
		SyncCommandHandler(string);

	public:
		virtual void process(Socket*, vector<string>&);
		virtual CommandHandler* clone();

	private:
		static SyncCommandHandler m_syncCmdHandler;
	};
}
