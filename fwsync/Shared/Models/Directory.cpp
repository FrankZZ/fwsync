#include "Directory.h"

using namespace std;

namespace fwsync
{
	void Directory::del(string)
	{
		
	}

	DIR* Directory::open(string szPath)
	{
		DIR* pDir = NULL;

		pDir = opendir(szPath.c_str());

		if (pDir == NULL)
		{
			delete pDir;
			throw("Directory cannot be opened");
		}

		return pDir;
	}

	void Directory::getListing(string szPath, vector<string>& vListing, bool bRecursive)
	{

		DIR* pDir = Directory::open(szPath);
		
		struct dirent* pEnt = NULL;

		int count = 0;
		while (pEnt = readdir(pDir))
		{
			if (strcmp(pEnt->d_name, ".") == 0 || strcmp(pEnt->d_name, "..") == 0)
				continue;

			string szCurrent(szPath);
			szCurrent.append(PATHSEPERATOR);
			szCurrent.append(pEnt->d_name);
			
			if (bRecursive && isDir(szCurrent))
			{
				getListing(szCurrent, vListing, true);
			}
			
			int iLastModified = getLastModifiedTime(szCurrent);
			
			szCurrent.append("|");
			szCurrent.append(to_string(iLastModified));

			vListing.push_back(szCurrent);
			count++;
		}

		delete pEnt;
		delete pDir;
	}

	bool Directory::isDir(string szPath)
	{
		struct stat s;

		if (stat(szPath.c_str(), &s) == 0)
			return s.st_mode & S_IFDIR ? true : false;
		else
			throw("Can't stat dir");
	}

	time_t Directory::getLastModifiedTime(string szPath)
	{
		struct stat s;

		if (stat(szPath.c_str(), &s) == 0)
			return s.st_mtime;
		else
			throw("Can't stat file");
	}

}
