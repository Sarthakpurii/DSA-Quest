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
 //2 stacks

//  class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(!root) return ans;
//         stack<TreeNode*> st1,st2;
//         st1.push(root);
//         while(!st1.empty()){
//             TreeNode* node=st1.top();
//             st1.pop();
//             if(node->left) st1.push(node->left);
//             if(node->right) st1.push(node->right);
//             st2.push(node);
//         }
//         while(!st2.empty()){
//             ans.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return ans;
//     }
// };


//1 stack + reversing the vector

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
            ans.push_back(node->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// 1 stack complex implementation
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(!root) return ans;
//         stack<TreeNode*> st;
//         TreeNode* node=root;
//         while(node!=nullptr || !st.empty()){
//             if(node!=nullptr){
//                 st.push(node);
//                 node=node->left;
//             }
//             else{
//                 TreeNode* temp=st.top()->right;
//                 if(temp==nullptr){
//                     temp=st.top();
//                     st.pop();
//                     ans.push_back(temp->val);
//                     while(!st.empty() && temp==st.top()->right){
//                         temp=st.top();
//                         st.pop();
//                         ans.push_back(temp->val);
//                     }
//                 }
//                 else{
//                     node=temp;
//                 }
//             }
//         }
//         return ans;
//     }
// };