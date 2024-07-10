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
// class Solution {
// public:
//     void preorder(TreeNode* root,int h,int &mh){
//         if(h>mh) mh=h;
//         if(root->left)preorder(root->left,h+1,mh);
//         if(root->right) preorder(root->right,h+1,mh);
//     }

//     int maxDepth(TreeNode* root) {
//         if(!root) return 0;
//         int maxheight=1;
//         preorder(root,1,maxheight);
//         return maxheight;
//     }
// };
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }
};