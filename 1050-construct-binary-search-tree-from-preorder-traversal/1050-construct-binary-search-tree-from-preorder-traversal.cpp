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
    TreeNode* helper(const vector<int>& preorder,int low,int high){
        cout<<preorder[low]<<endl;
        TreeNode* root=new TreeNode(preorder[low]);
        if( low==high) return root;
        int key=preorder[low];
        low++;
        int templow=low,temphigh=high;
        while(templow<=temphigh){
            int mid=templow+(temphigh-templow)/2;
            if(preorder[mid]<key) templow=mid+1;
            else temphigh=mid-1;
        }
        if(temphigh>=low) root->left=helper(preorder,low,temphigh);
        if(templow<=high) root->right=helper(preorder,templow,high);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};