#include <cctype>
using namespace std;

class Solution
{
public:
	bool isNumeric(char* str)
	{
		if (str == nullptr || *str == '\0')
			return false;
		int cur = 0;
		if (str[cur] == '+' || str[cur] == '-')
			++cur;
		bool point = true;
		bool split = false;
		while (str[cur]!='\0')
		{
			char tmp = str[cur];
			if(tmp=='.')
			{
				if(point)
				{
					++cur;
					point = false;
				}
				else
				{
					return false;
				}
			}
			else if(isdigit(tmp))
			{
				++cur;
			}
			else if(tmp=='e'||tmp=='E')
			{
				++cur;
				split = true;
				break;
			}
			else
			{
				return false;
			}
		}

		if(split)
		{
			if (str[cur] == '+' || str[cur] == '-')
				++cur;
			if (str[cur] == '\0')
				return false;
			while(str[cur]!='\0')
			{
				if (!isdigit(str[cur]))
					return false;
				++cur;
			}
		}
		return false;
	}
};