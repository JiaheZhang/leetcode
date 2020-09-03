
 // Definition for singly-linked list.
 public class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 }
 
class Solution {
    public void reorderList(ListNode head) {
    	if (head == null) {
    		return;
    	}
        Deque<ListNode> stack = new LinkedArray<>();
        ListNode p = head;
        while(p != null) {
        	stack.addLast(p);
        	p = p.next;
        }
        p = head;
        ListNode top;
        while(p != stack.peekLast() && p.next != stack.peekLast()) {
        	top = stack.pollLast();
        	top.next = p.next;
        	p.next = top;
        	p = top.next;
        }
        stack.peekLast().next = null;
    }
}