/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* p;
        ListNode* result = new ListNode(0);
        ListNode* temp;
        int i = 0;
        int flag = 0;
        
        result->next = head;
        temp = result;

        while(temp != NULL&&temp->next!=NULL){
            
            if(i>=1){
                if(temp->next->next == NULL){
                    p->next = temp->next;
                    p->next->next = temp;
                    temp->next = NULL;
                }
                else{
                    p->next = p->next->next;
                    temp->next = p->next->next;
                    p->next->next = temp;
                }
            }
            
            i++;
            
            p = temp;
            temp = temp->next;
            
        }
        return result->next;
    }
};
