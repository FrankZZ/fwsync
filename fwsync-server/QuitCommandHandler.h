#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"

namespace fwsync
{

	class QuitCommandHandler : public CommandHandler
	{
	private:
		QuitCommandHandler();
		QuitCommandHandler(std::string);

	public:
		virtual void process(Socket*, std::vector<std::string>&);
		virtual CommandHandler* clone();

	private:
		static QuitCommandHandler m_quitCmdHandler;
	};
}
