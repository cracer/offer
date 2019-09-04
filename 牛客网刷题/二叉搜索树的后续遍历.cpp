#include <vector>
using namespace std;

class Solution
{
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		int len = sequence.size();
		if (len == 0) return false;
		int i = 0;
		vector<int> vleft;
		vector<int> vright;
		while (i < len-1)
		{
			if(sequence[i]<sequence[len-1])
			{
				vleft.push_back(sequence[i]);
				i++;
			}
			else
			{
				break;
			}
		}
		while (i < len - 1)
		{
			if (sequence[i] > sequence[len - 1])
			{
				vright.push_back(sequence[i]);
				i++;
			}
			else
				return false;
		}

		bool left = true, right = true;
		if (vleft.size() != 0)
			left = VerifySquenceOfBST(vleft);
		if (vright.size() != 0)
			right = VerifySquenceOfBST(vright);
		return left && right;
	}
};