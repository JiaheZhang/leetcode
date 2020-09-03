 //Definition for singly-linked list.
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) { val = x; }
}
 
class Solution {
    public ListNode insertionSortList(ListNode head) {
    	if (head == null) {
    		return null;
    	}
    	ListNode pre = head;
    	ListNode p = head.next;

    	while (p != null) {
    		ListNode node = head;
    		if (p.val < head.val) {
    			pre.next = p.next;
    			p.next = head;
    			head = p;
    			p = pre.next;
    			continue;
    		}
    		while(p.val >= node.next.val && node.next != p) {
    			node = node.next;
    		}
    		if (node.next == p) {
    			pre = p;
    			p = p.next;
    		} else {
    			pre.next = p.next;
				p.next = node.next;
				node.next = p;
				p = pre.next;
    		}
    		
    	}

    	return head;

    }
}