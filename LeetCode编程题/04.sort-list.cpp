#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution 
{
public:
	ListNode *FindMid(ListNode *head)
	{
		ListNode *pSlow = head;
		ListNode *pFast = head;
		while (pFast != NULL && pFast->next != NULL && pFast->next->next != NULL)
		{
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}
		return pSlow;
	}
	ListNode *merge(ListNode *left, ListNode *right)
	{
		if (left == NULL)
			return right;
		if (right == NULL)
			return left;
		ListNode *mergehead = new ListNode(0);
		ListNode *head = mergehead;
		while (left != NULL && right != NULL)
		{
			if (left->val < right->val)
			{
				head->next = left;
				left = left->next;
			}
			else
			{
				head->next = right;
				right = right->next;
			}
			head = head->next;
		}
		if (left == NULL)
			head->next = right;
		if (right == NULL)
			head->next = left;
		return mergehead->next;
	}
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *mid = FindMid(head);
		ListNode *right = sortList(mid->next);
		mid->next = NULL;
		ListNode *left = sortList(head);
		return merge(left, right);
	}
	ListNode *pHead;
};

int main04()
{
	ListNode node1(2), node2(4), node3(1), node4(0), node5(9), node6(3), node7(8);
	Solution s;
	s.pHead = &node1;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node7;

	s.sortList(s.pHead);
	ListNode *currentnode = s.pHead;
	while (currentnode != NULL)
	{
		cout << currentnode->val << " ";
		currentnode = currentnode->next;
	}
	cout << endl;

	return 0;
}