#pragma once
#include <string>
#include "../Models/Socket.h"
#include <vector>

namespace fwsync
{
	class CommandHandler
	{
	public:
		CommandHandler();
		CommandHandler(string);
		virtual void process(Socket*, string) = 0;
		virtual CommandHandler* clone() = 0;
	};
}