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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ltor=true;
        while(!q.empty()){
            int s=q.size();
            vector<int> level(s,0);
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(ltor) level[i]=node->val;
                else level[s-i-1]=node->val;
            }
            if(ltor){
                ans.push_back(level);
                ltor=false;
            }
            else{
                ans.push_back(level);
                ltor=true;
            }
        }
        return ans;
    }
};