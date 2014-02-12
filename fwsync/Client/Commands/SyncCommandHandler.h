#pragma once
#include "../../Shared/Commands/CommandHandler.h"
#include <string>
#include <vector>
#include <map>
#include "../../Shared/Models/socket.h"
#include "../../Shared/Models/Directory.h"
#include "../../Shared/Models/FileReader.h"

using namespace std;

namespace fwsync
{

	class SyncCommandHandler : public CommandHandler
	{
		private:
			SyncCommandHandler();
			SyncCommandHandler(string);
			void localExists(Socket*, string, string);
			void remoteExists(Socket*, string);
			void bothExist(string);

		public:
			virtual void process(Socket*, string);
			virtual CommandHandler* clone();

		private:
			static SyncCommandHandler m_syncCmdHandler;
	};
}
