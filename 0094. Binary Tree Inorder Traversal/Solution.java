/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class TreeNode {
	TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
 }


class Solution {
	private List<Integer> res = new ArrayList<>();
    public List<Integer> inorderTraversal(TreeNode root) {
    	DFS(root);
    	return res;
    }

    private void DFS(TreeNode root){
    	if (root == null) {
    		return;
    	}
    	DFS(root.left);
    	res.add(root.val);
    	DFS(root.right);
    }
}

