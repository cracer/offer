#include<iostream>
#include<cstdlib>
using namespace std;
//”–Œ Ã‚
int main111(void)
{
	int arr[10] = { 0,6,3,2,7,5,4,9,1,8 };
	;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int i = 2; i <= 10; i++)
	{
		if(arr[i]<arr[i-1])
		{
			arr[0] = arr[i];
			int j = i - 1;
			do
			{
				arr[j + 1] = arr[j];
				j--;
			} while (arr[0] < arr[j]);
			arr[j + 1] = arr[0];
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
