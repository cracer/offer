#include <vector>
using namespace std;

class Solution
{
public:
	bool Find(int target,vector<vector<int> > array)
	{
		int row = (int)array.size();
		int column = (int)array[0].size();
		if (row == 0 || column == 0)
			return false;
		if (target<array[0][0] || target>array[row - 1][column - 1])
			return false;
		int i = 0, j = column - 1;
		while (i<row&&j>=0)
		{
			if (array[i][j] > target)
				j--;
			else if (array[i][j] < target)
				i++;
			else
				return true;
		}
		return false;
	}
};