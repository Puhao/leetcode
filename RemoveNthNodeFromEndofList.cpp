#include <iostream>


using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head;
        ListNode *q = head;
        ListNode *pre = NULL;
        if (head == NULL)
        	return NULL;
        if (n<=0)
        	return NULL;
        while(--n)
        {
        	if(p->next == NULL)
        		return NULL;
        	p = p->next;
        }
        while(p->next != NULL)
        {
        	pre = q;
        	p = p->next;
        	q = q->next;
        }
        if (q == head)
        	return q->next;
        pre->next = q->next;
        return head;
    }


int main()
{
	return 0;
}