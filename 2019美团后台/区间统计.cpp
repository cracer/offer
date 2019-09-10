#include <iostream>
#include <vector>
#include <map>
/*
 * 思路： 
1.给出k，区间长度固定 
2.求出固定区间相同元素的数量大于t即可 
3.用map存储每个元素以及其数量，每个区间是个滑动窗口，每次区间向前移动一个位置，
只需要第一次遍历区间，对map初始化，随后区间每移动一次，只需要改变新区间right值
对应数量和上个区间left值对应数量即可

 */
using namespace std;
map<int, int> MAP;
bool isFirst = true;
bool IsAccessT(vector<int>& arr, int left, int right, int t) {
	if (isFirst) {//首个区间初始化
		isFirst = false;
		for (int i = left; i <= right; i++) {
			MAP[arr[i]]++;
		}
	}
	else {
		MAP[arr[left - 1]]--;
		MAP[arr[right]]++;
	}
	auto it = MAP.begin();
	for (; it != MAP.end(); it++)
		if (it->second >= t)
			return true;
	return false;

}

int fun(vector<int>& arr, int k, int t) {
	int count = 0;
	for (int left = 0; left < arr.size(); ++left) {
		int right = k - 1 + left;
		if (right >= arr.size())
			break;
		if (right < arr.size() && IsAccessT(arr, left, right, t))
			count++;
	}
	return count;
}
int main() {
	int n, k, t;
	cin >> n >> k >> t;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	int res = fun(arr, k, t);
	cout << res << endl;
	system("pause");
	return 0;
}

