#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};


class Solution
{
public:
	vector<int> temp;
	void DFSserial(TreeNode* pRoot)
	{
		if (!pRoot)
			temp.push_back(0xFFFFFFFF);
		else
		{
			temp.push_back(pRoot->val);
			DFSserial(pRoot->left);
			DFSserial(pRoot->right);
		}
	}

	TreeNode* DFSDeserial(int* str)
	{
		if(*str==0xFFFFFFFF)
		{
			++str;
			return nullptr;
		}
		TreeNode* res = new TreeNode(*str);
		str++;
		res->left = DFSDeserial(str);
		res->right = DFSDeserial(str);
	}

	char* Serialize(TreeNode* root) //序列化
	{
		temp.clear();
		DFSserial(root);
		int len = temp.size();
		int* res = new int[len];
		for (int i = 0; i < len; i++)
		{
			res[i] = temp[i];
		}
		return (char*)res;
	}

	TreeNode* Deserialize(char* str) //反序列化
	{
		int* p = (int*)str;
		return DFSDeserial(p);
	}

};