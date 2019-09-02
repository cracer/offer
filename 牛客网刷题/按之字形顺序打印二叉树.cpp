#include <vector>
#include <stack>
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
	vector<vector<int> > Print(TreeNode* pRoot)
	{
		vector<vector<int> > res;
		if (pRoot == nullptr)
			return res;
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		s1.push(pRoot);
		TreeNode* tmp;
		vector<int> v;
		while (!s1.empty()||!s2.empty())
		{
			if(!s1.empty())
			{
				while (!s1.empty())
				{
					tmp = s1.top();
					v.push_back(tmp->val);
					if (tmp->left)
						s2.push(tmp->left);
					if (tmp->right)
						s2.push(tmp->right);
					s1.pop();
				}
				res.push_back(v);
				v.clear();
			}
			else
			{
				while(!s2.empty())
				{
					tmp = s2.top();
					v.push_back(tmp->val);
					if (tmp->right)
						s2.push(tmp->right);
					if (tmp->left)
						s2.push(tmp->left);
					s2.pop();
				}
				res.push_back(v);
				v.clear();
			}
		}
		return res;
	}
};