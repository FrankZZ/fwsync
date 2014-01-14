#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"

namespace fwsync
{

	class InfoCommandHandler : public CommandHandler
	{
	private:
		InfoCommandHandler();
		InfoCommandHandler(std::string);

	public:
		virtual void process(Socket*, std::vector<std::string>&);
		virtual CommandHandler* clone();

	private:
		static InfoCommandHandler m_infoCmdHandler;
	};
}
