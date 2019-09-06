using namespace std;
class Solution
{
public:
	int rectCover(int number)
	{
		if (number <= 2)
			return number;
		int first = 1;
		int second = 2;
		for (int i = 3; i <= number; i++)
		{
			int temp = first + second;
			first = second;
			second = temp;
		}
		return second;

	}
};