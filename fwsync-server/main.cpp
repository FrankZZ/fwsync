#include "constants.h"
#include "socket.h"
#include "fwsync-server.h"
#include "CommandFactory.h"
#include "CommandHandler.h"
#include <string>

using namespace fwsync;

int main()
{
	Server *server = new Server();

	CommandHandler* ch = CommandFactory::create(std::string("get"));

	server->listen(1080);

	return 0;
}
