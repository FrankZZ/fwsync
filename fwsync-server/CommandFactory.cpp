#include "CommandFactory.h"

namespace fwsync
{

	void CommandFactory::assign(std::string szCommand, CommandHandler* pCmdHandler)
	{
		CommandHandlerMap& cmdHandlers = getMap();
		CommandHandlerMap::const_iterator ciFind = cmdHandlers.find(szCommand);

		if (ciFind == cmdHandlers.end())
		{
			cmdHandlers[szCommand] = pCmdHandler;
		}
	}

	CommandHandler* CommandFactory::create(std::string szCommand)
	{
		CommandHandlerMap& cmdHandlers = getMap();

		CommandHandlerMap::const_iterator ciFind = cmdHandlers.find(szCommand);

		if (ciFind == cmdHandlers.end())
		{
			return NULL;
		}
		else
			return ciFind->second->clone();
	}

	CommandFactory::CommandHandlerMap& CommandFactory::getMap()
	{
		static CommandHandlerMap ciMap;
		return ciMap;
	}

}