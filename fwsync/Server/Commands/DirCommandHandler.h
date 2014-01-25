#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include "../../Shared/Models/socket.h"
#include "time.h"
#include "../../Shared/Models/Directory.h"

using namespace std;

namespace fwsync
{

	class DirCommandHandler : public CommandHandler
	{
	private:
		DirCommandHandler();
		DirCommandHandler(string);

	public:
		virtual void process(Socket*, vector<string>&);
		virtual CommandHandler* clone();

	private:
		static DirCommandHandler m_dirCmdHandler;
	};
}
