#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numbersOfZeros(vector<int> v)
{
	int count = 0;
	int len = v.size();
	int left = 0;
	int right = len - 1;
	sort(v.begin(),v.end());
	while (left < right)
	{
		if (v[left]+v[right]==0)
		{
			count++;
			left++;
			right--;
		}
		if (v[left]+v[right] > 0)
			right--;
		if (v[left] + v[right] < 0)
			left++;
	}
	return count;
}

int main()
{
	vector<int> inputs;
	int num;
	do
	{
		cin >> num;
		inputs.push_back(num);
	} while (getchar()!='\n');
	cout << numbersOfZeros(inputs);
	return 0;

}