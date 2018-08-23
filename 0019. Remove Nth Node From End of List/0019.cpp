/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

*/

#include<iostream>

using namespace std;



// Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode* next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first;
        ListNode* second;
        ListNode* pre;
        first = head;
        second = head;
        pre = head;
        if(n == 1){//delete the tail
            if(first->next == NULL){//only one element in list
                head = head->next;
            }
            else{
                while(first->next != NULL){
                    pre = first;
                    first = first->next;
                }
                pre->next = NULL;
                
            }
            
        }
        else{
            for(int i = 0;i < n-1;i++){
                first = first->next;
            }
            //if tail, delete the head
            if(first->next == NULL){
                head = head->next;
            }
            else{//go to next until tail
                while(first->next != NULL){
                    pre = second;
                    second = second->next;
                    first = first->next;
                }
                pre->next = second->next;
            }
        }
        

        return head;
    }
};

int main(){
    Solution s;
    int a;
    ListNode* head;
    ListNode* p;
    p = head;
    while(cin>>a){
        if(a==0) break;
        else {
            ListNode* temp = new ListNode(a);
            p->next = temp;
            p = p->next;
        }
    }
    p = head;
    while(p->next != NULL){
        p = p->next;
        cout<<p->val<<endl;
    }

    head = s.removeNthFromEnd(head,3);

    p = head;
    while(p->next != NULL){
        p = p->next;
        cout<<p->val<<endl;
    }

    system("pause");


    return 0;
}
