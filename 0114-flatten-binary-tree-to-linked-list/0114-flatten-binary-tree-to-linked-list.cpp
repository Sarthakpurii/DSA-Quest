/**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* preorder(TreeNode* root){
//         TreeNode* head=new TreeNode(root->val);
//         TreeNode* temp=head;
//         if(root->left)temp->right=preorder(root->left);
//         while(temp->right) temp=temp->right;
//         if(root->right) temp->right=preorder(root->right);
//         return head;
//     }
//     void flatten(TreeNode* &root) {
//         if(root){
//         TreeNode* ans=preorder(root);
//         root=ans;}
//         // while(root){
//         //     cout<<root->val<<"->";
//         //     root=root->right;
//         // }
//     }
// };
class Solution {
public:
    //<----recursive--->

    // TreeNode* prev=nullptr;
    // void flatten(TreeNode* root) {
    //     if(!root)  return;
    //     flatten(root->right);
    //     flatten(root->left);
    //     root->right=prev;
    //     root->left=nullptr;
    //     prev=root;
    // }

    //<---Iterative--->

    // void flatten(TreeNode* root){
    //     if(!root) return;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while(!st.empty()){
    //         TreeNode* node=st.top();
    //         st.pop();
    //         if(node->right) st.push(node->right);
    //         if(node->left) st.push(node->left);
    //         if(!st.empty()) node->right=st.top();
    //         else node->right=nullptr;
    //         node->left=nullptr;
    //     }

    //Morris traversal
    
    void flatten(TreeNode* root){
        if(!root) return;
        TreeNode* curr=root;
        while(curr){
            if(curr->left){
                TreeNode* temp=curr->left;
                while(temp->right) temp=temp->right;
                temp->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};
