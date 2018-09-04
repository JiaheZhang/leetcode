/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* result = new ListNode(0);
        ListNode* p;
        int i = 0;
        vector<ListNode*> v(k);
        
        if(k == 1) return head;
        
        result->next = head;
        p = result;
        while(p != NULL){
            for(int j = 0;j < k-1;j++){
                v[j] = v[j+1];
            }
            v[k-1] = p;
            p = p->next;
            i++;
            
            if(i % k == 0 && p != NULL){
                v[0]->next = p;
                v[1]->next = p->next;
                for(int j = 0;j < k-2;j++){
                    v[j+2]->next = v[j+1];
                }
                p->next = v[k-1];
                p = v[1];
            }
        }
        
        
        return result->next;
    }
};