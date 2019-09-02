#include <string>
#include <map>
using namespace std;

class Solution
{
public:
	string s = "";
	map<char, int> m;
	void Insert(char ch)
	{
		s += ch;
		++m[ch];
	}

	char FirstAppearingOnce()
	{
		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			if (m[s[i]] == 1)
				return s[i];
		}
		return '#';
	}

};