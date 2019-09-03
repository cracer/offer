#include <iostream>
using namespace std;

int Count1Num(int num)
{
	int tmp = 0;
	while(num)
	{
		tmp++;
		num &= (num - 1);
	}
	return tmp;
}

int main111()
{
	int input;
	cin >> input;
	cout << Count1Num(input);
	return 0;
}