/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

//第一直觉是二指针法
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
    	ListNode p1 = head;
    	ListNode res = p1;
    	if (p1 == null) {
    		return p1;
    	}
    	ListNode p2 = head.next;
    	ListNode p2Pre = head;
    	int cnt = 1;
    	while(p2 != null){
    		if (p2.val != p2Pre.val) {
    			p1.next = p2;
    			p1 = p1.next;
    		} 
    		p2Pre = p2;
    		p2 = p2.next;
    	}
        p1.next = null;

    	return res;
    }
}


class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}