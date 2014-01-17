#include "Directory.h"

using namespace std;

namespace fwsync
{
	void Directory::del(wstring)
	{
		
	}

	WDIR* Directory::open(wstring szPath)
	{
		WDIR* pDir = NULL;
		struct wdirent* pEnt = NULL;

		pDir = wopendir(szPath.c_str());

		if (pDir == NULL)
		{
			throw("Directory cannot be opened");
		}

		return pDir;
	}

	wstring Directory::getListing(wstring szPath)
	{
		wstring szListing;

		WDIR* pDir = Directory::open(szPath);
		
		struct wdirent* pEnt = NULL;

		if (pDir == NULL)
		{
			delete pDir;
			delete pEnt;
			throw("Directory cannot be opened");
		}

		int count = 0;
		while (pEnt = wreaddir(pDir))
		{
			if (count > 0)
				szListing.append(L"\n");

			szListing.append(pEnt->d_name);

			count++;
		}

		delete pEnt;
		delete pDir;

		return szListing;
	}
}