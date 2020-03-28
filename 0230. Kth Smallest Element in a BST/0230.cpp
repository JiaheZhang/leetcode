#include <iostream>
#include <vector>

using namespace std; 



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nums;
    void dfs(TreeNode* root, vector<int>& nums){
        if(root == NULL) return;
        dfs(root->left, nums);
        nums.push_back(root->val);
        dfs(root->right, nums);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, nums);
        return nums[k-1];
        
    }
};