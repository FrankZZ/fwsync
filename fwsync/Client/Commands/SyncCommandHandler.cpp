#include "SyncCommandHandler.h"

using namespace std;

namespace fwsync
{

	SyncCommandHandler SyncCommandHandler::m_syncCmdHandler(string("sync"));

	SyncCommandHandler::SyncCommandHandler(string sCommand) : CommandHandler(sCommand)
	{

	}

	SyncCommandHandler::SyncCommandHandler()
	{

	}

	void SyncCommandHandler::process(Socket* socket, string szLine)
	{
		vector<string> params = vector<string>();
		strsplit(szLine, params, ' ', 3);

		if (params.size() != 3)
			throw("SYNTAX: SYNC [local dir] [remote dir]");

		vector<string> vsListing = vector<string>();
		Directory::getListing(params[1], vsListing, true);

		socket->write("RDIR ");
		socket->writeline(params[2]);

		char line[MAX_PATH + 1];

		socket->readline(line, MAXPATH);
		
		if (strcmp(line, "OK") != 0)
		{
			while (socket->readline(line, MAXPATH) > 0)
			{
				cout << line << endl;
			}
			throw("Aborted");
		}

		map<string, time_t> msLocalListing = map<string, time_t>();
		map<string, time_t> msRemoteListing = map<string, time_t>();
		
		vector<string> vsEntry = vector<string>();
		
		for (int i = 0; i < vsListing.size(); i++)
		{
			strsplit(vsListing[i], vsEntry, '|');
			
			// Relative path
			vsEntry[0].erase(0, params[1].length() + 1);
			
			msLocalListing[vsEntry[0]] = vsEntry.size() == 2 ? stoul(vsEntry[1]) : 0;

			vsEntry.clear();
		}

		while (socket->readline(line, MAXPATH) > 0)
		{
			strsplit(line, vsEntry, '|');
			
			// Relative path
			vsEntry[0].erase(0, params[2].length() + 1);
			
			msRemoteListing[vsEntry[0]] = (vsEntry.size() == 2 ? stoul(vsEntry[1]) : -1);

			vsEntry.clear();
		}

		typedef map<string, time_t>::iterator it_type;

		for (it_type it = msLocalListing.begin(); it != msLocalListing.end(); it++)
		{
			it_type it2 = msRemoteListing.find(it->first);

			if (it2 != msRemoteListing.end())
			{
				if (it->second > 0 && it->second > it2->second)
				{
					// Both exists but local is newer (modtime), overwrite PUT to server
					string szLocalPath = string(params[1]);
					string szRemotePath = string(params[2]);
					szLocalPath.append(PATHSEPERATOR);
					szRemotePath.append(PATHSEPERATOR);
					szLocalPath.append(it->first);
					szRemotePath.append(it->first);
					localExists(socket, szLocalPath, szRemotePath);
				}
			}
			else
			{
				if (it->second > 0)
				{
					// Only local exists, PUT to server
					string szLocalPath = string(params[1]);
					string szRemotePath = string(params[2]);
					szLocalPath.append(PATHSEPERATOR);
					szRemotePath.append(PATHSEPERATOR);
					szLocalPath.append(it->first);
					szRemotePath.append(it->first);
					localExists(socket, szLocalPath, szRemotePath);
				}
			}
				
		}

		for (it_type it = msRemoteListing.begin(); it != msRemoteListing.end(); it++)
		{
			
			it_type it2 = msLocalListing.find(it->first);

			if (it2 == msLocalListing.end())
			{
				// Only remote exists, DEL from server
				string szPath = string(params[2]);
				szPath.append(PATHSEPERATOR);
				szPath.append(it->first);
				remoteExists(socket, szPath);
			}
				
		}
		cout << "Syncing successful" << endl;
	}

	CommandHandler* SyncCommandHandler::clone()
	{
		return new SyncCommandHandler();
	}

	void SyncCommandHandler::localExists(Socket* socket, string szLocalPath, string szRemotePath)
	{
		socket->write("PUT null ");
		socket->writeline(szRemotePath);
		char line[MAXPATH + 1];

		socket->readline(line, MAXPATH);

		if (strcmp(line, "OK") != 0)
		{
			while (socket->readline(line, MAXPATH) > 0)
			{
				cout << line << endl;
			}
			throw("Aborted");
		}

		FileReader* fw = new FileReader(szLocalPath);

		fw->writeToSocket(socket);

		delete fw;

		while (socket->readline(line, MAXPATH) > 0)
		{
			cout << line << endl;
		}
	}

	void SyncCommandHandler::remoteExists(Socket* socket, string szPath)
	{
		socket->write("DEL ");
		socket->writeline(szPath);

		char line[MAXPATH + 1];

		while (socket->readline(line, MAXPATH) > 0)
		{
			cout << line << endl;
		}
	}
}