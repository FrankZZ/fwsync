#pragma once
#include "CommandHandler.h"
#include <string>
#include <vector>
#include "socket.h"
#include "time.h"
#include "Directory.h"

using namespace std;

namespace fwsync
{

	class DirCommandHandler : public CommandHandler
	{
	private:
		DirCommandHandler();
		DirCommandHandler(wstring);

	public:
		virtual void process(Socket*, vector<wstring>&);
		virtual CommandHandler* clone();

	private:
		static DirCommandHandler m_dirCmdHandler;
	};
}
