#include <string>
using namespace std;
class Solution1 
{
public:
	bool isMatch(string s, string p) 
	{
		if (p.empty()) return s.empty();
		auto firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
		if (p.length() >= 2 && p[1] == '*')
			return isMatch(s, p.substr(2)) || (firstMatch&&isMatch(s.substr(1), p));
		else
			return firstMatch&&isMatch(s.substr(1), p.substr(1));
	}
};

class Solution2//效率高
{
public:
	bool isMatch(string s, string p)
	{
		return subMatch(s.c_str(), p.c_str());
	}

	bool subMatch(const char* s, const char* p)
	{
		if (*p == 0) return *s == 0;
		auto firstMatch = *s && (*s == *p || *p == '.');
		if (*(p + 1) == '*')
			return subMatch(s, p + 2) || (firstMatch&&subMatch(++s, p));
		else
			return firstMatch&&subMatch(++s, ++p);
	}
};


class Solution3
{
public:
	bool subMatch(int sIndex, int pIndex, string s, string p){
		int pNextIndex = pIndex + 1;
		if (sIndex == s.length() ^ pIndex == p.length()){
			if (pNextIndex < p.length() && p.at(pNextIndex) == '*'){
				return subMatch(sIndex, pIndex + 2, s, p);
			}
			return false;
		}
		if (sIndex == s.length() && pIndex == p.length())
			return true;
		char sChar = s.at(sIndex);
		char pChar = p.at(pIndex);
		if (pNextIndex != p.length()){
			if (p.at(pNextIndex) != '*'){
				//下一个字符不是'*';
				if (sChar == pChar || pChar == '.'){
					//当前字符相等或模式字符为'.'，匹配;
					if (subMatch(sIndex + 1, pIndex + 1, s, p))
						return true;
				}
				else{
					//不匹配
					return false;
				}
			}
			else {
				//下一个字符是'*';
				if (sChar == pChar || pChar == '.'){
					//当前字符相等或模式字符为'.'，匹配;
					if (subMatch(sIndex + 1, pIndex, s, p))
						return true;
					if (subMatch(sIndex, pIndex + 2, s, p))
						return true;
					if (subMatch(sIndex + 1, pIndex + 2, s, p))
						return true;
				}
				else {
					//不匹配
					if (subMatch(sIndex, pIndex + 2, s, p))
						return true;
				}
			}
		}
		else {
			if (sChar == pChar || pChar == '.'){
				if (subMatch(sIndex + 1, pIndex + 1, s, p)){
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		//this place
		return false;
	}

	bool isMatch(string s, string p) {
		return subMatch(0, 0, s, p);
	}

};

