#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include "../../Shared/Models/socket.h"
#include "../../Shared/constants.h"
#include "../../Shared/Models/SocketException.h"
#include "../../Shared/utility.h"

using namespace std;

namespace fwsync
{

	class DirCommandHandler : public CommandHandler
	{
	private:
		DirCommandHandler();
		DirCommandHandler(string);

	public:
		virtual void process(Socket*, string);
		virtual CommandHandler* clone();

	private:
		static DirCommandHandler m_dirCmdHandler;
	};
}
