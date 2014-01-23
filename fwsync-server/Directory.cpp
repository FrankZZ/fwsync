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
		struct dirent* pEnt = NULL;

		pDir = opendir(szPath.c_str());

		if (pDir == NULL)
		{
			throw("Directory cannot be opened");
		}

		return pDir;
	}

	string Directory::getListing(string szPath)
	{
		string szListing;

		DIR* pDir = Directory::open(szPath);
		
		struct dirent* pEnt = NULL;

		if (pDir == NULL)
		{
			delete pDir;
			delete pEnt;
			throw("Directory cannot be opened");
		}

		int count = 0;
		while (pEnt = readdir(pDir))
		{
			if (count > 0)
				szListing.append("\n");

			szListing.append(pEnt->d_name);

			count++;
		}

		delete pEnt;
		delete pDir;

		return szListing;
	}
}