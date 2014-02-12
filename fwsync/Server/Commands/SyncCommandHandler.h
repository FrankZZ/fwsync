#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include "../../Shared/Models/socket.h"
#include "../../Shared/Models/Directory.h"
#include "../../Shared/constants.h"
#include "../../Shared/utility.h"
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
		virtual void process(Socket*, string);
		virtual CommandHandler* clone();

	private:
		static SyncCommandHandler m_syncCmdHandler;
	};
}
