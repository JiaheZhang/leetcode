/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode(0);
        ListNode* p;
        int len;
        int temp = 9999999999;
        int index = 0;
        int num = 0;
        
        p = head;
        len = lists.size();
        
        while(true){
            num = 0;
            temp = 9999999999;
            for(int i = 0;i < len;i++){

                //find min val
                if(lists[i] != NULL){
                    if(lists[i]->val < temp){
                        temp = lists[i]->val;
                        index = i;
                        
                    }
                }
                else num++;

            }  
            if(num == len) break;

            //cout<<index<<endl;
            p->next = lists[index];
            
            lists[index] = lists[index]->next;
            p = p->next;
        }
        return head->next;
        
        
    }
};