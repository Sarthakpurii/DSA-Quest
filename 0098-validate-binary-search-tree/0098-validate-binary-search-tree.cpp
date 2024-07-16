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
    bool isValidBST(TreeNode* root) {
        TreeNode* curr=root;
        int prev;
        bool ans=true,prevIni=false;
        while(curr){
            if(!curr->left){
                if(prevIni && prev>=curr->val) ans=false;
                prev=curr->val;
                prevIni=true;
                curr=curr->right;
            }
            else{
                TreeNode* temp=curr->left;
                while(temp->right && temp->right!=curr) temp=temp->right;
                if(!temp->right){
                    temp->right=curr;
                    curr=curr->left;
                }
                else{
                    if(prevIni && prev>=curr->val) ans=false;
                    prev=curr->val;
                    prevIni=true;
                    temp->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return ans;
        
    }
};