#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;
//有问题
int fun(int arr[], int len)
{
	vector<int> v;
	int index = 0;
	int tmp = arr[0] > arr[1] ? 2 : 1;//判断第一个人
	v.push_back(tmp);
	for (int i = 1; i <= len - 2; i++)
	{
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
			v.push_back(1);
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			v.push_back(v.back() + 1);
		if(arr[i]<arr[i-1]&&arr[i]>arr[i+1])
		{
			index = i;
			break;
		}
	}
	vector<int> vtmp;
	int last = arr[len - 1] < arr[len - 2] ? 1 : 2;
	vtmp.push_back(last);
	for(int j = len-2; j>=index+1;j--)
	{
		if (arr[j] > arr[j + 1])
			vtmp.push_back(vtmp.back() + 1);
		if (arr[j] < arr[j + 1] && arr[j] < arr[j - 1])
			vtmp.push_back(1);
	}
	int value = arr[index] > arr[index + 1] ? vtmp.back() + 1 : 1;
	vtmp.push_back(value);
	reverse(vtmp.begin(), vtmp.end());
	v.insert(v.end(), vtmp.begin(), vtmp.end());

	int sum = accumulate(v.begin(), v.end(), 0);
	return sum;
}

int main()
{
	// int len;
	// cin >> len;
	// int *arr = new int[len];
	// for (int i = 0; i < len; i++)
	// {
	// 	cin >> arr[i];
	// }

	 // int arr[] = { 3,6,3,5,6,2 };
	 // cout << fun(arr, 6);

	  // int arr[] = { 2,4,2,6,1,7,8,9,2,1 };
	  // cout << fun(arr, 10);
	  // int arr[] = { 2,4,2,6,1,7,8,9,10,1 };
	  // cout << fun(arr, 10);
	// int arr[] = { 3,6,5,2,1,2 };
	// cout << fun(arr, 6);
	int arr[] = { 6,3,1,5 };
	cout << fun(arr, 4);
	system("pause");
	return 0;
}