#include "CommandHandler.h"
#include "../Models/CommandFactory.h"

using namespace std;

namespace fwsync
{

	CommandHandler::CommandHandler()
	{

	}

	CommandHandler::CommandHandler(string sCommand)
	{
		CommandFactory::assign(sCommand, this);
	}
}