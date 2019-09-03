using namespace std;


/*
 *	k     --> 0
 *	k+1   --> 1
 *	k+2   --> 2
 *	...
 *	...
 *	k-2   --> n-2
 *	k-1   --> n-1
 */

//f[1] = 0; £¨i = 1£©
//f[i] = (f[i - 1] + m) % i;  (i > 1)

class Solution
{
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n < 1 || m < 1)
			return -1;
		int last = 0;     
		for (int i = 2; i <= n; i++)
		{
			last = (last + m) % i;
		}
		return last;
	}
};