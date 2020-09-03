class ListNode {
	int val;
	ListNode next;
	ListNode(int x) {
		val = x;
		next = null;
	}
}

class Solution {
	private List<Integer> res = new ArrayList<>();
    public List<Integer> preorderTraversal(TreeNode root) {
    	if (root != null) {
    		helper(res, root);
    	}
    	return res;
    }

    private void helper(List<Integer> res, TreeNode root) {
    	res.add(root.val);
    	if (root.left != null) {
    		helper(res, root.left);
    	}
    	if (root.right != null) {
    		helper(res, root.right);
    	}
    }

}