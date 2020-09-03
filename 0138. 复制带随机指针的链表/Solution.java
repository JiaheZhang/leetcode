
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Node p = head;
        while(p != null) {
            Node node = new Node(p.val);
            node.next = p.next;
            node.random = p.random;
            p.next = node;
            p = node.next;
        }
        p = head.next;

        while(p != null) {
            if (p.random != null) {
                p.random = p.random.next;
            }
            if (p.next == null) {
                break;
            }
            p = p.next.next;
        }

        p = head;
        Node p2 = head.next;
        Node res = head.next;
        while(p != null) {
            if (p2.next == null) {
                p.next = null;
                break;
            }
            p.next = p2.next;
            p2.next = p2.next.next;

            p = p.next;
            p2 = p2.next;
        }
        return res;

    }
}