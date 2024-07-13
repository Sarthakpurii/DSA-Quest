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
    TreeNode* build(const vector<int> & inorder,const vector<int> & postorder,int& root, pair<int,int> range,unordered_map<int,int> & mp){
        TreeNode* roo=new TreeNode(postorder[root]);
        if(range.first==range.second) return roo;
        
        int idx=mp[postorder[root]];
        if(range.second>=idx+1 && root>-1){
            root--;
            TreeNode* right=build(inorder,postorder,root,{idx+1,range.second},mp);
            roo->right=right;
        }
        if(range.first<=idx-1 && root>-1){
            root--;
            TreeNode* left=build(inorder,postorder,root,{range.first,idx-1},mp);
            roo->left=left;
        }
        return roo;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size(),root=n-1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        return build(inorder,postorder,root,{0,n-1},mp);
    }
};