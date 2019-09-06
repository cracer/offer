using namespace std;

class Solution
{
public:
	int jumpFloor(int number)
	{
		if (number <= 2)
			return number;
		int a = 1;
		int b = 2;
		int result = a + b;
		for (int i = 3; i <= number; i++)
		{
			result = a + b;
			a = b;
			b = result;
		}
		return result;
	}
};