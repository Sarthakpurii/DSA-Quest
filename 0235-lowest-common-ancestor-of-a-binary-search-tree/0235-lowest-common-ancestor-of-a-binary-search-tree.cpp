/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(!root || root==p || root==q) return root;

//         TreeNode* left=lowestCommonAncestor(root->left,p,q);
//         TreeNode* right=lowestCommonAncestor(root->right,p,q);

//         if(left && right) return root;
//         else if(left) return left;
//         else if (right) return right;
//         return nullptr;

//     }
// };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;

        if(root->val>q->val && root->val>p->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val<q->val && root->val<p->val){
            return lowestCommonAncestor(root->right,p,q);
        }

        return root;
        
    }
};