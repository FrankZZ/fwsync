#pragma once

#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace fwsync
{
	void wstrsplit(wstring str, vector<wstring> &tokens, wchar_t delim);
}
