using namespace std;


//  f(n)=f(n-1)+f(n-2)+ *** +f(1)+1 
//  f(n-1)=f(n-2)+ *** +f(1)+1
//  f(n)-f(n-1)=f(n-1)£¬¼´f(n)=2*f(n-1)

class Solution
{
public:
	int jumpFloorII(int number)
	{
		if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		return 2 * jumpFloorII(number - 1);
	}
};