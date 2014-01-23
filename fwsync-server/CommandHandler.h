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
		CommandHandler(string);
		virtual void process(Socket*, vector<string>&) = 0;
		virtual CommandHandler* clone() = 0;
	};
}