#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;


int candy(vector<int> &ratings) {
	if (ratings.size() <= 1) return 1;

	int sum = 0;
	vector<int> assign(ratings.size(), 1);

	for (int i = 1; i < assign.size(); ++i) {
		if (ratings[i] > ratings[i - 1]) {
			if (assign[i - 1] + 1 > assign[i]) {
				assign[i] = assign[i - 1] + 1;
			}
		}
	}

	for (int i = assign.size() - 2; i >= 0; --i) {
		if (ratings[i] > ratings[i + 1]) {
			if (assign[i + 1] + 1 > assign[i]) {
				assign[i] = assign[i + 1] + 1;
			}
		}
	}

	for (int i = 0; i < assign.size(); ++i)
		sum += assign[i];
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
	// int arr[] = { 6,3,1,5 };
	// cout << fun(arr, 4);

	vector<int> v{ 3,6,3,5,6,2 };
	vector<int> v1{ 2,4,2,6,1,7,8,9,2,1 };
	// cout << candy(v);
	cout << candy(v1);
	system("pause");
	return 0;
}