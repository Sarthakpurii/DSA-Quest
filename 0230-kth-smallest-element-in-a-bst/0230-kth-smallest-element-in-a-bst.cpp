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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        int cnt=0;
        int res=-1;
        while(curr){
            if(!curr->left){
                cnt++;
                if(cnt==k) res=curr->val;
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
                    cnt++;
                    if(cnt==k) res=curr->val;
                    temp->right=nullptr;
                    curr=curr->right;
                }
            }
        }
        return res;
    }
};