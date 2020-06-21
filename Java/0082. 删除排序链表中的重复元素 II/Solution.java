/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
    	ListNode p1 = head,p2 = head;
    	if (p1 == null) {
    		return p1;
    	}
    	ListNode tmp = new ListNode(0);
    	ListNode res = tmp;
    	while(p2 != null) {
    		int cnt = 0;
	    	while(p2 != null && p1.val == p2.val){
	    		cnt++;
	    		p2 = p2.next;
	    	}
	    	if (cnt == 1) {
	    		tmp.next = p1;
	    		tmp = tmp.next;
	    	}
	    	p1 = p2;
	    }
	    tmp.next = null;
    	return res.next;
    }
}

class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}