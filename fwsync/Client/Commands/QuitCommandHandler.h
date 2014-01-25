#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include "../../Shared/Models/socket.h"
#include "time.h"

namespace fwsync
{

	class QuitCommandHandler : public CommandHandler
	{
	private:
		QuitCommandHandler();
		QuitCommandHandler(string);

	public:
		virtual void process(Socket*, vector<string>&);
		virtual CommandHandler* clone();

	private:
		static QuitCommandHandler m_quitCmdHandler;
	};
}
