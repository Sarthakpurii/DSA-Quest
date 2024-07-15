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
    TreeNode* deleteNode(TreeNode* root, int key) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!root) return root;
        if(root->val==key){
            if(root->left){
                TreeNode* temp=root->left;
                while(temp->right) temp=temp->right;
                temp->right=root->right;
                return root->left;
            }
            else return root->right;
        }
        TreeNode *temp=root,*prev=nullptr;
        while(temp){
            if(temp->val==key){
                if(temp->val>prev->val){ 
                    prev->right=temp->left;
                    while(prev->right) prev=prev->right;
                    prev->right=temp->right;
                }
                else{
                    prev->left=temp->right;
                    while(prev->left) prev=prev->left;
                    prev->left=temp->left;
                }
                break;
            }
            if(temp->val>key){
                prev=temp;
                temp=temp->left;
            }
            else{
                prev=temp;
                temp=temp->right;
            }
        }
        return root;
    }
};