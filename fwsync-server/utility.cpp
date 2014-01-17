#include "utility.h"

using namespace std;

namespace fwsync
{
	void wstrsplit(wstring str, vector<wstring> &tokens, wchar_t delim)
	{
		wstring buf;
		wstringstream ss(str); // Insert the string into a stream

		while (getline(ss, buf, delim))
			tokens.push_back(buf);
	}
}
