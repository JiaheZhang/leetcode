#include <iostream>
#include <vector>

using namespace std; 



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int depth(TreeNode* root){
        if(root == NULL) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        return max(left,right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return abs(depth(root->left) - depth(root->right) <= 1) && isBalanced(root->left) && isBalanced(root->right);

    }
        

};