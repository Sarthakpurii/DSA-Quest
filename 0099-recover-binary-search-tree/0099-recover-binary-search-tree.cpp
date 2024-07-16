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
    void recoverTree(TreeNode* root) {
        TreeNode *curr=root,*first=nullptr,*second=nullptr;
        while(curr->left) curr=curr->left;
        int prev=curr->val;
        curr=root;
        while(curr){
            if(curr->left){
                TreeNode* temp=curr->left;
                while(temp->right && temp->right!=curr) temp=temp->right;
                if(!temp->right){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    if(curr->val<prev) second=curr;
                    if(!second) first=curr;
                    temp->right=nullptr;
                    prev=curr->val;
                    curr=curr->right;
                    // prev=curr->val;
                }
            }
            else{
                if(curr->val<prev) second=curr;
                if(!second) first=curr;
                prev=curr->val;
                curr=curr->right;
            }
        }
        // cout<<second->val;
        first->val=first->val+second->val;
        second->val=first->val-second->val;
        first->val=first->val-second->val;

        
    }
};