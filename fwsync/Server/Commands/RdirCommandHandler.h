#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include "../../Shared/Models/socket.h"
#include "time.h"
#include "../../Shared/Models/Directory.h"

using namespace std;

namespace fwsync
{

	class RdirCommandHandler : public CommandHandler
	{
	private:
		RdirCommandHandler();
		RdirCommandHandler(string);

	public:
		virtual void process(Socket*, string);
		virtual CommandHandler* clone();

	private:
		static RdirCommandHandler m_rdirCmdHandler;
	};
}
