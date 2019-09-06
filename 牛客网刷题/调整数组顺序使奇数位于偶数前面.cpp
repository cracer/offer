#include <vector>
using namespace std;

class Solution
{
public:
	void reOrderArray(vector<int> &array)
	{
		int len = array.size();
		int index = 0;
		int value = 0;
		while(index < len)
		{
			if (array[index] % 2 != 0)
			{
				int temp = array[index];
				for (int i = index; i > value; i--)
				{
					array[i] = array[i - 1];
				}
				array[value] = temp;
				index++;
				value++;
			}
			else
				index++;
		}
	}
};