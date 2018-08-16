#include<iostream>
using namespace std;


struct ListNode
{
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode():val(0),next(NULL){}
}; 

class Solution
{
	public:
	    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			ListNode* p1 = l1;
			ListNode* p2 = l2;
			int carryFlag = 0;
			ListNode* result = new ListNode(0);
			ListNode* p3 = result;
			p3->val = (p1->val + p2->val + carryFlag) % 10;
			carryFlag = (p1->val + p2->val + carryFlag) / 10;
			p1 = p1->next;
			p2 = p2->next;
			while(p1 != NULL && p2 != NULL)//two list get val together 
			{
				ListNode* temp = new ListNode((p1->val + p2->val + carryFlag) % 10);
                if(p1->val + p2->val + carryFlag >= 10)
				    carryFlag = 1;
                else
                    carryFlag = 0;
				p3->next = temp;
				p3 = temp;
				p1 = p1->next;
				p2 = p2->next;
			}
			while(p1 != NULL)//one by one 
			{
				ListNode* temp = new ListNode((p1->val + carryFlag) % 10);
				if(p1->val + carryFlag >= 10)
				    carryFlag = 1;
                else
                    carryFlag = 0;
				p3->next = temp;
				p3 = temp;
				p1 = p1->next;
			}
			while(p2 != NULL)//one by one
			{
				ListNode* temp = new ListNode((p2->val + carryFlag) % 10);
				if(p2->val + carryFlag >= 10)
				    carryFlag = 1;
                else
                    carryFlag = 0;
				p3->next = temp;
				p3 = temp;
				p2 = p2->next;
			}
            if(carryFlag == 1) 
            {
                ListNode* temp = new ListNode(carryFlag);
				p3->next = temp;
				p3 = temp;
            }
			p3->next = NULL;
			return result;
	    }
};

int main()
{
	ListNode* l1 = new ListNode(3);
	ListNode* l2 = new ListNode(3);
	ListNode* p;
	ListNode* sum;
	int i = 2;
	p = l1;

	while(i > 0)
	{
		ListNode *temp = new ListNode(i);  
		p->next = temp;
		p = temp;
		i--;
	}
	p->next = NULL;
	
	i = 3;
	p = l2;

	while(i > 0)
	{
		ListNode *temp = new ListNode(i);  
		p->next = temp;
		p = temp;
		i--;
	}
	p->next = NULL;

	Solution s;
	sum = s.addTwoNumbers(l1,l2);
	p = sum;
	while(p != NULL)
	{
		cout<<p->val;
		p = p->next;
	}
	return 0;
}
