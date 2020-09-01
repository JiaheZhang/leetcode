/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/


public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}
 
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
    	return buildTreeHelper(inorder, postorder, 0, inorder.length, 0, postorder.length);
    }

    private TreeNode buildTreeHelper(int[] inorder, int[] postorder, int left, int right, int start, int end) {
    	if (start == end) {
    		return null;
    	}
    	TreeNode node = new TreeNode(postorder[end - 1]);
    	int index = arrayFindIndex(inorder, node.val);

    	node.left = buildTreeHelper(inorder, postorder, left, index, start, index - left + start);
    	node.right = buildTreeHelper(inorder, postorder, index + 1, right, index - left + start,end - 1);
    	return node;
    }

    private int arrayFindIndex(int[] nums, int val) {
    	for (int i = 0; i < nums.length; ++i) {
    		if (nums[i] == val) {
    			return i;
    		}
    	}
    	return -1;
    }
}