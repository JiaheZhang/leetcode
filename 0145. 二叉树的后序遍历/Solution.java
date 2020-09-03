class Solution {
	private List<Integer> res = new ArrayList<>();
    public List<Integer> postorderTraversal(TreeNode root) {
        if (root != null) {
    		helper(res, root);
    	}
    	return res;
    }
    private void helper(List<Integer> res, TreeNode root) {
    	if (root.left != null) {
    		helper(res, root.left);
    	}
    	if (root.right != null) {
    		helper(res, root.right);
    	}
    	res.add(root.val);
    }
}