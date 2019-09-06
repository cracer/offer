class Solution
{
public:
	int Fibonacci(int n)
	{
		int arr[39] = { 0 };
		arr[0] = 0;
		arr[1] = 1;
		for (int i = 2; i < n + 1; i++)
		{
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		return arr[n];


	}
};