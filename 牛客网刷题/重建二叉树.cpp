#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		int vlen = vin.size();
		if (vlen == 0) return nullptr;
		vector<int> preLeft, preRight, vinLeft, vinRight;
		TreeNode* node = new TreeNode(pre[0]);
		int index = 0;
		for (int i = 0; i < vlen; i++)
		{
			if(vin[i]==pre[0])
			{
				index = i;
				break;
			}
		}
		for (int i = 0; i < index; i++)
		{
			preLeft.push_back(pre[i + 1]);
			vinLeft.push_back(vin[i]);
		}
		for(int i=0;i<vlen-index-1;i++)
		{
			preRight.push_back(pre[i + index + 1]);
			vinRight.push_back(vin[i + index + 1]);
		}
		node->left = reConstructBinaryTree(preLeft, vinLeft);
		node->right = reConstructBinaryTree(preRight, vinRight);
		return node;
	}
};