#include <iostream>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

int AddNum(int a,int b,int &carry)
{
	int sum = a + b + carry;
	if (sum >= 10)
	{
		carry = 1;
		return sum - 10;
	}
	else
	{
		carry = 0;
		return sum;
	}
}

ListNode *AddList(ListNode *a, ListNode *b,int &carry)
{
	if (a == NULL && b == NULL)
		if (carry)
			return new ListNode(1);
		else
			return NULL;
	if (a == NULL)
	{
		ListNode *tmp = new ListNode(AddNum(0,b->val,carry));
		tmp->next = AddList(NULL,b->next,carry);
		return tmp;
	}
	if (b == NULL)
	{
		ListNode *tmp = new ListNode(AddNum(a->val,0,carry));
		tmp->next = AddList(a->next,NULL,carry);
		return tmp;
	}
	ListNode *tmp = new ListNode(AddNum(a->val,b->val,carry));
	tmp->next = AddList(a->next,b->next,carry);
	return tmp;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int carry = 0;
		return  AddList(l1,l2,carry);        
 }

 int main()
 {
 	ListNode *a = new ListNode(4);
 	ListNode *b = new ListNode(7);
 	ListNode *sum = addTwoNumbers(a,b);
 	while(sum!=NULL)
 	{
 		cout << sum->val << "-";
 		sum = sum->next;
 	}
 	return 0;
 }