#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *pre,ListNode *next)
{
	ListNode *last = pre->next;
	ListNode *cur = last->next;
	while(cur != next)
	{
		last->next = cur->next;
		cur->next = pre->next;
		pre->next = cur;
		cur = last->next;
	}
	return last;
}

ListNode *reverseKGroup(ListNode *head, int k) 
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
{
	if (head == NULL)
		return NULL;
	ListNode *Host = new ListNode(0);
	ListNode *pre = Host;
	Host->next = head;
	int i = 0;
	while(head)
	{
		i++;
		if (i % k == 0)
		{
			pre = reverse(pre,head->next);
			head = pre->next;
		}
		else
			head = head->next;
	}
	return Host->next;
}

int main()
{
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(3);
	ListNode *l3 = new ListNode(4);
	ListNode *l4 = new ListNode(5);
	ListNode *l5 = new ListNode(1);
	l5->next = l4;
	l4->next = l3;
	l3->next = l2;
	l2->next = l1;
	ListNode *p = reverseKGroup(l5,3);
	while(p != NULL)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
	return 0;
}