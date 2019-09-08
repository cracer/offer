#include <iostream>
#include <vector>
#include <set>
using namespace std;

int drinkCoffee(int k, int m, set<int> s)
{
	int res = 0;
	int noDrink = 0;
	for (int i = 1; i <= 30; i++)
	{
		if (noDrink == k)
		{
			res++;
			noDrink = 0;
			continue;
		}
		if (s.count(i) == 1)
		{
			res++;
			noDrink = 0;
		}
		else if (noDrink < k)
		{
			noDrink++;
		}
	}
	return res;
}

int main()
{
	int cnt;
	cin >> cnt;
	vector<int> v;
	for (int i = 0; i < cnt; i++)
	{
		int *arr = new int[2];
		for (int j = 0; j < 2; j++)
		{
			cin >> arr[j];
		}
		
		set<int> s;
		for (int k = 0; k < arr[1]; k++)
		{
			int num;
			cin >> num;
			s.insert(num);
		}
		int index = drinkCoffee(arr[0], arr[1], s);
		v.push_back(index);
	}
	for (int i = 0; i < (int)v.size(); i++)
	{
		cout << v[i] << endl;
	}
	system("pause");
	return 0;
}