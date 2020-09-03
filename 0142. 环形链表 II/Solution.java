 //Definition for singly-linked list.
class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode node = hasCycle(head);
        if (node == null) {
        	return null;
        }
        node = node.next;

        ListNode p = head;
        while(p != node) {
        	p = p.next;
        	node = node.next;
        }
        return node;
    }

    public ListNode hasCycle(ListNode head) {
        if (head == null) {
        	return null;
        }
        ListNode p1 = head;
        ListNode p2 = p1.next;
        while (p2 != null) {
        	if (p1 == p2) {
        		return p1;
        	}
        	if (p2.next == null) {
        		return null;
        	}
        	p2 = p2.next.next;
        	p1 = p1.next;
        }
        return null;
    }
}