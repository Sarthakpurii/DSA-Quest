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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=desc.size();
        unordered_map<int,TreeNode*> mpp;
        unordered_set<int> sett;
        for(const auto& v:desc){
            TreeNode* parent,*child;
            if(mpp.find(v[0])==mpp.end()) parent=new TreeNode(v[0]);
            else parent=mpp[v[0]];
            if(mpp.find(v[1])==mpp.end()) child=new TreeNode(v[1]);
            else child=mpp[v[1]];
            if(v[2]==1) parent->left=child;
            else parent->right=child;
            mpp[v[0]]=parent;
            mpp[v[1]]=child;
            sett.insert(v[0]);
        }
        for(const auto& v:desc) sett.erase(v[1]);
        
        return mpp[*sett.begin()];
    }
};