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
		CommandHandler(wstring);
		virtual void process(Socket*, vector<wstring>&) = 0;
		virtual CommandHandler* clone() = 0;
	};
}