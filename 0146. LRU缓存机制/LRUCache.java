class LRUCache {

	private int capacity;

	private Map<Integer, Node> map;

	private Node head;

	private Node tail;


    public LRUCache(int capacity) {
    	this.capacity = capacity;
    	map = new HashMap<>(capacity);
    	head = new Node(0,0);
    	tail = new Node(0,0);
    	head.next = tail;
    	tail.pre = head;
    }
    
    public int get(int key) {
    	Node p = map.get(key);
    	if (p == null) {
    		return -1;
    	}
    	fixDeque(p);

    	return p.value;

    }
    
    public void put(int key, int value) {
    	Node p = map.get(key);
    	if (p == null) {
    		Node node = new Node(key, value);
    		map.put(key, node);
    		insertTail(node);
    		if (map.size() > capacity) {
    			map.remove(head.next.key);
    			delNode(head.next);
    		}

    	} else {
    		fixDeque(p);
    		p.value = value;
    	}
    }

    private void delNode(Node p) {
    	p.pre.next = p.next;
    	p.next.pre = p.pre;
    }

    private void insertTail(Node p) {
    	tail.pre.next = p;
    	p.next = tail;

    	p.pre = tail.pre;
    	tail.pre = p;
    }

    private void fixDeque(Node p) {
    	delNode(p);
    	insertTail(p);
    }
}

class Node {
	int key;
	int value;
	Node next;
	Node pre;
	public Node(int key, int value) {
		this.key = key;
		this.value = value;
	}
}
// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
// [null,null,null,1,null,2,null,1,3,4]

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */