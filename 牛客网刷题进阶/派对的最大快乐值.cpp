#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct HappyNode
{
	int happy = 0;
	int parent = -1;
	vector<int> child;
	int maxHappyValue = 0;
};

int CalcMaxHappyValue(vector<HappyNode> &inputs, int index)
{
	auto &tmpNode = inputs[index];
	if (tmpNode.child.empty()) return tmpNode.happy;
	if (tmpNode.maxHappyValue != 0) return tmpNode.maxHappyValue;
	/* 分为两种情况：
	 * 1、去掉当前节点
	 * 2、保留当前节点
	 * 分别计算两种情况的happy值
	 */
	int value1 = tmpNode.happy, value2 = 0;
	//去掉
	for (int i = 0; i < tmpNode.child.size(); i++)
	{
		auto &childIndex = tmpNode.child[i];
		for (int j = 0; j < inputs[childIndex].child.size(); j++)
		{
			value1 += CalcMaxHappyValue(inputs, inputs[childIndex].child[j]);
		}
	}
	//保留
	for (int i = 0; i < tmpNode.child.size(); i++)
	{
		value2 += CalcMaxHappyValue(inputs, tmpNode.child[i]);
	}
	tmpNode.maxHappyValue = max(value1, value2);
	return tmpNode.maxHappyValue;
	
}


int main()
{
	int n, root;
	vector<HappyNode> inputs;
	HappyNode hnode;
	cin >> n >> root;
	inputs.resize(n + 1);
	for (int i = 1; i < n + 1; i++)
	{
		cin >> inputs[i].happy;
	}
	int a, b;
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		inputs[b].parent = a;
		inputs[a].child.emplace_back(b);

	}
	cout << CalcMaxHappyValue(inputs, root) << endl;
}

