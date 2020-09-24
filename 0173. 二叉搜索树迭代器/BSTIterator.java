/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class BSTIterator {

	private Deque<TreeNode> stack;

    public BSTIterator(TreeNode root) {
    	stack = new LinkedList<>();
    	helper(root);
    }
    
    /** @return the next smallest number */
    public int next() {
    	TreeNode node = stack.pollLast();

    	helper(node.right);

    	return node.val;
    }
    
    /** @return whether we have a next smallest number */
    public boolean hasNext() {
    	return !stack.isEmpty();
    }

    private void helper(TreeNode node) {
    	while(node != null) {
    		stack.addLast(node);
    		node = node.left;
    	}
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */