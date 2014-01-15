#pragma once
#include <string>
#include "Socket.h"
#include <vector>

namespace fwsync
{
	class CommandHandler
	{
	public:
		CommandHandler();
		CommandHandler(std::string);
		virtual void process(Socket*, std::vector<std::string>&) = 0;
		virtual CommandHandler* clone() = 0;
	};
}