#pragma once
#include <map>
#include <string>
#include "CommandHandler.h"

namespace fwsync
{

	class CommandFactory
	{
	public:
		static CommandHandler* create(std::string);

	private:
		typedef std::map<std::string, CommandHandler*> CommandHandlerMap;

		static CommandHandlerMap& getMap();

		static void assign(std::string, CommandHandler*);
		friend class CommandHandler;
	};
}