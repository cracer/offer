#include <vector>
using namespace std;

class Solution
{
public:
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		int low = 0;
		int high = rotateArray.size() - 1;
		while (low<high)
		{
			int mid = (low + high) / 2;
			if (rotateArray[mid] > rotateArray[high])
				low = mid + 1;
			else if(rotateArray[mid]== rotateArray[high])
			{
				low -= 1;
				high -= 1;
			}
			else
			{
				high = mid;
			}
		}
		return rotateArray[low];
	}
};