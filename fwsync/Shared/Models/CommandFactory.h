#pragma once
#include <map>
#include <string>
#include "../Commands/CommandHandler.h"

namespace fwsync
{

	class CommandFactory
	{
	public:
		static CommandHandler* create(string);

	private:
		typedef std::map<string, CommandHandler*> CommandHandlerMap;

		static CommandHandlerMap& getMap();

		static void assign(string, CommandHandler*);
		friend class CommandHandler;
	};
}