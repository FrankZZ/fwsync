#include "CommandHandler.h"
#include "CommandFactory.h"

namespace fwsync
{

	CommandHandler::CommandHandler()
	{

	}

	CommandHandler::CommandHandler(std::string sCommand)
	{
		CommandFactory::assign(sCommand, this);
	}
}