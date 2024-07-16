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
    // void helper(TreeNode* root,int start,int dest, bool& s,bool&d,string& spath,string& dpath){
    //     if(!root ||(s&&d)) return;
    //     if(root->val==start) s=true;
    //     else if(root->val==dest) d=true;
    //     if(s&&d) return;
    //     if(!s && !d){
    //         helper(root->left,start,dest,s,d,spath+"L",dpath+"L");
    //         helper(root->right,start,dest,s,d,spath+"R",dpath+"R");
    //     }
    //     else if(s)
    //         helper(root->left,start,dest,s,d,spath,dpath+"L");
    //         helper(root->right,start,dest,s,d,spath,dpath+"R");
    // }
    TreeNode* lca(TreeNode* root,int start,int dest){
        if(!root || root->val==start || root->val==dest) return root;
        TreeNode* left=lca(root->left,start,dest);
        TreeNode* right=lca(root->right,start,dest);
        if(left && right) return root;
        if(left) return left;
        if(right) return right;
        return nullptr;
    }
    string lcaToStart,lcaToDest;
    void findpath(TreeNode* root, const int& start,const int& dest,string& path){
        if(!root) return;
        if(root->val==start) lcaToStart=path;
        else if(root->val==dest) lcaToDest=path;

        path.push_back('L');
        findpath(root->left,start,dest,path);
        path.pop_back();

        path.push_back('R');
        findpath(root->right,start,dest,path);
        path.pop_back();
    }
    string getDirections(TreeNode* root, int start, int dest) {
        TreeNode* ances=lca(root,start,dest);
        // cout<<ances->val;
        string path="";
        findpath(ances,start,dest,path);
        for(char &c:lcaToStart) c='U';
        return lcaToStart+lcaToDest;
    }
};