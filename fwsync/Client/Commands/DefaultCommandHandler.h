#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include "../../Shared/Models/socket.h"
#include "../../Shared/constants.h"
#include "../../Shared/Models/SocketException.h"

using namespace std;

namespace fwsync
{

	class DefaultCommandHandler : public CommandHandler
	{
	private:
		DefaultCommandHandler();
		DefaultCommandHandler(string);

	public:
		virtual void process(Socket*, vector<string>&);
		virtual CommandHandler* clone();

	private:
		static DefaultCommandHandler m_defaultCmdHandler;
	};
}
