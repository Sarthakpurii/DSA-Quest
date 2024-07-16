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
    stack<TreeNode*> left,right;
    TreeNode* low,*high;
    void next(){
        low=low->right;
        while(low){
            left.push(low);
            low=low->left;
        }
        low=left.top();
        // cout<<"Low->"<<low->val<<endl;
        left.pop();
    }
    void prev(){
        high=high->left;
        while(high){
            right.push(high);
            high=high->right;
        }
        high=right.top();
        // cout<<"High->"<<high->val<<endl;
        right.pop();
    }
    bool findTarget(TreeNode* root, int k) {
        low=root;
        high=root;
        while(low){
            left.push(low);
            low=low->left;
        }
        low=left.top();
        left.pop();

        while(high){
            right.push(high);
            high=high->right;
        }
        high=right.top();
        right.pop();
        while(low!=high){
            int temp=low->val+high->val;
            if(temp==k) return true;
            if(temp<k) next();
            else prev();
        }
        return false;  
    }
};