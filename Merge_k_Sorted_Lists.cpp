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

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.size() == 0)
        	return NULL;
        for(int i=1;i<lists.size();i=i*2)
        {
        	int j=0;
        	while((j+i)<lists.size())
        	{
        		lists[j] = mergeTwoLists(lists[j],lists[j+i]);
        		j = j+i+i;
        	}
        }
        return lists[0];
        
    }


int main()
{
	ListNode *l1 = new ListNode(2);
	ListNode *l2 = new ListNode(3);
	ListNode *l3 = new ListNode(4);
	ListNode *l4 = NULL;
	ListNode *l5 = new ListNode(7);
	vector<ListNode *> l = {l1,l2,l3,l4,l5};
	ListNode *p = mergeKLists(l);
	while(p != NULL)
	{
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;
	return 0;
}