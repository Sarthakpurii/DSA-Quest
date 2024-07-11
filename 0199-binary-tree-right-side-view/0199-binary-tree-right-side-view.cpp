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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        stack<pair<TreeNode*,int>> st;
        ans.push_back(root->val);
        int y=0;
        st.push({root,0});
        while(!st.empty()){
            int curr=st.top().second;
            TreeNode* node=st.top().first;
            st.pop();
            if(node->right) st.push({node->right,curr+1});
            if(node->left) st.push({node->left,curr+1});
            if(curr>y){
                ans.push_back(node->val);
                y++;
            } 
            else ans[curr]=node->val;
        }
        return ans;
    }
};