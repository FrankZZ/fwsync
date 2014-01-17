#pragma once
#include <map>
#include <string>
#include "CommandHandler.h"

namespace fwsync
{

	class CommandFactory
	{
	public:
		static CommandHandler* create(wstring);

	private:
		typedef std::map<wstring, CommandHandler*> CommandHandlerMap;

		static CommandHandlerMap& getMap();

		static void assign(wstring, CommandHandler*);
		friend class CommandHandler;
	};
}