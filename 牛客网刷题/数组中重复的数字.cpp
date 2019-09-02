#include <map>
using namespace std;


class Solution
{
public:
	bool duplicate(int numbers[],int length,int* duplication)
	{
		map<int, int> m;
		for (int i = 0; i < length; i++)
		{
			if(m[numbers[i]]!=0)
			{
				*duplication = numbers[i];
			}
			else
			{
				m[numbers[i]]++;
			}
		}
		return false;
	}
};