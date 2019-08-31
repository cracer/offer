#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> result;
		if(num.size() >= size && size >= 1)
		{
			deque<int> index;
			for (unsigned int i = 0; i < size; i++)
			{
				while(!index.empty() && num[i] >= num[index.back()])
				{
					index.pop_back();
				}
				index.push_back(i);
			}
			for(unsigned int i=size;i < num.size();i++)
			{
				result.push_back(num[index.])
			}
		}
	}
};