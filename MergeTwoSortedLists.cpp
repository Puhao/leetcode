#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
{
	if (l1==NULL && l2 == NULL)
		return NULL;
	if (l1==NULL)
		return l2;
	if (l2== NULL)
		return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists(l1->next,l2);
		return l1;
	}
	l2->next = mergeTwoLists(l1,l2->next);
	return l2;
}



int main()
{
	ListNode *l1 = new ListNode(3);
	ListNode *l2 = new ListNode(4);
	ListNode *l3 = mergeTwoLists(l1,l2);
	while(l3 != NULL)
	{
		cout << l3->val << ' ';
		l3 = l3->next;
	}
	cout << endl;
	return 0;
}