/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
	private List<Integer> res = new ArrayList<>();
    public List<Integer> rightSideView(TreeNode root) {
    	if (root == null) {
    		return res;
    	}

    	Queue<TreeNode> queue = new LinkedList<>();
    	queue.add(root);

    	while (!queue.isEmpty()) {
    		int len = queue.size();
    		for (int i = 0; i < len; ++i) {
    			TreeNode p = queue.poll();
    			if (p.left != null) {
    				queue.add(p.left);
    			}
    			if (p.right != null) {
    				queue.add(p.right);
    			}
    			if (i == len - 1) {
    				res.add(p.val);
    			}
    		}
    	}
    	return res;
    }
}