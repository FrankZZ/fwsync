#include "constants.h"
#include "fwsync-server.h"
#include <string>

using namespace fwsync;

int main()
{
	Server *server = new Server();

	server->listen(1080);

	return 0;
}
