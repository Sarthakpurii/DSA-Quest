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
    // int findIdx(const vector<int> inorder,int root,pair<int,int> range){
    //     for(int i=range.first;i<=range.second;i++){
    //         if(inorder[i]==root) return i;
    //     }
    //     return -1;
    // }
    TreeNode* build(const vector<int> preorder,const vector<int> inorder,int & root,pair<int,int> range){
        TreeNode* roo=new TreeNode(preorder[root]);
        if(range.first==range.second) return roo;
        int idx;
        for(int i=range.first;i<=range.second;i++){
            if(inorder[i]==preorder[root]){
                idx=i;
                break;
            } 
        }
        if(range.first<=idx-1 && root<preorder.size()){
            root++;
            TreeNode* left=build(preorder,inorder,root,{range.first,idx-1});
            roo->left=left;
        }
        if(range.second>=idx+1 && root<preorder.size()){
            root++;
            TreeNode* right=build(preorder,inorder,root,{idx+1,range.second});
            roo->right=right;
        }
        return roo;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root=0,n=preorder.size();
        return build(preorder,inorder,root,{0,n-1});
    }
};