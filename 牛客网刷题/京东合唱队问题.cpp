#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a < b;
}

int findMaxArr(int* arr, int length)
{
	int *copy = new int[length];
	for (int i = 0; i < length; i++)
		copy[i] = arr[i];
	sort(copy, copy + length, cmp);
	int tmp1 = 0, tmp2 = 0, result = 0;
	for (int j = 0; j < length; j++)
	{
		tmp1 += arr[j];
		tmp2 += copy[j];
		if (tmp1 == tmp2)
		{
			result++;
			tmp1 = 0;
			tmp2 = 0;
		}
	}
	return result;
}

int main()
{
	int arr[6] = { 1, 5, 9, 4, 8, 6 };

	int len = sizeof(arr) / sizeof(arr[0]);
	cout << len << endl;
	cout << findMaxArr(arr, len);
	system("pause");
	return 0;
}