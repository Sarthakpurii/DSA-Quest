/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode *root,int &path){
        if(!root) return 0;
        int lp=helper(root->left,path);
        int rp=helper(root->right,path);
        int maxpathtillnow=max(root->val,max(root->val+rp,root->val+lp));
        path=max(rp+lp+root->val,max(maxpathtillnow,path));
        return maxpathtillnow;
        
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int path=INT_MIN;
        helper(root,path);
        return path;
    }
};