#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int CHAR_CNT = 10;
const char *cNumChar[CHAR_CNT] = { "零","一","二","三","四","五","六","七","八","九" };
const char *cUnitSection[] = { "","万","亿","万亿" };
const char *cUnitChar[] = { "","十","百","千" };

void Section2Chinese(unsigned int sec, string& chnStr)
{
	string tmpStr = "";
	int pos = 0;
	bool zero = true;
	while (sec>0)
	{
		int index = sec % 10;
		if(index==0)
		{
			if(!zero)
			{
				zero = true;
				chnStr.insert(0, cNumChar[index]);
			}
		}
		else
		{
			zero = false;
			tmpStr = cNumChar[index];
			tmpStr += cUnitChar[pos];
			chnStr.insert(0, tmpStr);
		}
		pos++;
		sec /= 10;
	}

}

void Num2Chinese(unsigned int num,string &chnStr)
{
	int pos = 0;
	bool zero = false;
	while (num>0)
	{
		string tmpStr = "";
		unsigned int sec = num % 10000;
		if (zero)
			chnStr.insert(0, cNumChar[0]);
		Section2Chinese(sec, tmpStr);
		tmpStr += (sec != 0) ? cUnitSection[pos] : cUnitSection[0];
		chnStr.insert(0, tmpStr);
		zero = (sec < 1000) && (sec > 0);
		num /= 10000;
		pos++;
	}
}




int main111()
{
	unsigned int num;
	string str;
	while(cin>>num&&(num!=0))
	{
		string str = "";
		Num2Chinese(num, str);
		for(int i=0;i<str.length();i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}