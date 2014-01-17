#include "CommandFactory.h"

using namespace std;

namespace fwsync
{

	void CommandFactory::assign(wstring szCommand, CommandHandler* pCmdHandler)
	{
		CommandHandlerMap& cmdHandlers = getMap();
		CommandHandlerMap::const_iterator ciFind = cmdHandlers.find(szCommand);

		if (ciFind == cmdHandlers.end())
		{
			cmdHandlers[szCommand] = pCmdHandler;
		}
	}

	CommandHandler* CommandFactory::create(wstring szCommand)
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