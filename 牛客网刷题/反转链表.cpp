using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};

class Solution
{
public:
	ListNode* ReverseList(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;
		else
		{
			ListNode* newHead = ReverseList(head->next);
			head->next->next = head;
			head->next = nullptr;
			return newHead;
		}
	}
};