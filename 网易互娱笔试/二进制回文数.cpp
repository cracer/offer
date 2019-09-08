
#include <iostream>
using namespace std;
int main1()
{
	int num;
	cin >> num;
	int *arr = new int[num];
	int tmp;
	for (int i = 0; i < num;i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < num; i++)
	{
		int sum = 0;
		for (int j = arr[i]; j; j /= 2)
		{
			tmp = j % 2;
			sum = sum << 1 + tmp;
		}
		if (sum == arr[i])
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	system("pause");
	return 0;

}


