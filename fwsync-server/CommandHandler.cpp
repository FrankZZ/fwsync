#include "CommandHandler.h"
#include "CommandFactory.h"

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