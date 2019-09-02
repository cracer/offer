using namespace std;

class Solution
{
public:
	bool match(char* str,char* pattern)
	{
		if (*str == '\0'&&*pattern == '\0')
			return true;
		if(*str==*pattern||(*pattern=='.')&&*str!='\0')
		{
			if (*(pattern + 1) != '*')
				return match(++str, ++pattern);
			return match(str, pattern + 2) || match(str, pattern + 1);
		}
		else if(*(pattern+1)=='*')
		{
			pattern += 2;
			return match(str, pattern);
		}
		return false;
	}
};