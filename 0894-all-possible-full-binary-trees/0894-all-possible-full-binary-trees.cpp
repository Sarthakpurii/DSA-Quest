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
    vector<TreeNode*> memo(int i,unordered_map<int,vector<TreeNode*>>& dp){
        if(dp.find(i)!=dp.end()) return dp[i];
        if(i==1){
            TreeNode* temp=new TreeNode();
            return dp[1]={temp};
        }
        vector<TreeNode*> v;
        for(int k=1;k<i-1;k+=2){
            vector<TreeNode*> l=memo(k,dp),r=memo(i-1-k,dp);
            for(auto lef:l){
                for(auto rig:r){
                    TreeNode* root=new TreeNode();
                    root->left=lef;
                    root->right=rig;
                    v.push_back(root);
                }
            }
        }
        return dp[i]=v;
        
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        if(!(n&1)) return {};
        unordered_map<int,vector<TreeNode*>> dp;
        return memo(n,dp);
    }
};