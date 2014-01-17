#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"

using namespace std;

namespace fwsync
{

	class SyncCommandHandler : public CommandHandler
	{
	private:
		SyncCommandHandler();
		SyncCommandHandler(wstring);

	public:
		virtual void process(Socket*, vector<wstring>&);
		virtual CommandHandler* clone();

	private:
		static SyncCommandHandler m_syncCmdHandler;
	};
}
