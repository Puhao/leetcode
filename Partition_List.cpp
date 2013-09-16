#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *l = new ListNode(0); 
        ListNode *g = new ListNode(0);
        ListNode *r = new ListNode(0);
        ListNode *p,*q;
        while(head)
        {
        	if(head->val < x)
        	{
        		p = l->next;
        		q = head->next;
        		l->next = head;
        		head->next = p;
        		head = q;
        	}
        	else
        	{
        		p = g->next;
        		q = head->next;
        		g->next = head;
        		head->next = p;
        		head = q;
        	}
        }
        while(g->next)
        {
        	p = g->next;
        	q = r->next;
        	g->next = p->next;
        	p->next = q;
        	r->next = p;
        }
        while(l->next)
        {
        	p = l->next;
        	q = r->next;
        	l->next = p->next;
        	p->next = q;
        	r->next = p;
        }
        return r->next;
    }


int main()
{
	ListNode *a1 = new ListNode(3);
	ListNode *a2 = new ListNode(5);
	a2->next = a1;
	ListNode *a3 = new ListNode(2);
	a3->next = a2;
	ListNode *p = partition(a3,3);
	while(p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}