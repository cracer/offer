#include <vector>
using namespace std;

class Solution
{
public:
	int GetNumberOfK(vector<int> data,int k)
	{
		int count = 0;
		for(auto &i:data)
		{
			if (i == k)
				count++;
		}
		return count;
	}
};