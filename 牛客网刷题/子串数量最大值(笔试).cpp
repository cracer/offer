#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef map<string, int>::iterator CountIte;
struct compare
{
	bool operator()(CountIte left, CountIte right)
	{
		return left->second > right->second;
	}
};

vector<string> findSubString(string str, int len)
{
	vector<string> v;
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= len - i; j++)
		{
			v.push_back(str.substr(i, j));
		}
	}
	return v;
}


void maxCnt(const vector<string> &v, int k)
{
	map<string, int> cntMap;
	for (int i = 0; i < (int)v.size(); i++)
	{
		cntMap[v[i]]++;
	}
	
	multiset<CountIte, compare> sortSet;
	CountIte cit = cntMap.begin();
	while (cit!=cntMap.end())
	{
		sortSet.insert(cit);
		++cit;
	}
	auto as = sortSet.begin();

	cout << (*as)->second << endl;

	//multiset<CountIte, compare>::iterator it1 = sortSet.begin();
	/*for (; it1 != sortSet.end(); ++it1)
	{
		if (k--)
			cout << (*it1)->first << ":" << (*it1)->second << endl;
	}*/
}

void main1111()
{
	string str;
	cin >> str;

	int strlen = str.length();
	vector<string> temp = findSubString(str, strlen);
	
	maxCnt(temp, 1);// 1 可不用传参

	system("pause");

	
}