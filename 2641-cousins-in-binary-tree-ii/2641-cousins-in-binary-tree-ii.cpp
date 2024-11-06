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

    TreeNode* replaceValueInTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({nullptr,root});
        unordered_map<TreeNode*,int> mp;
        mp[nullptr]=root->val;
        int totsum=root->val;
        while(!q.empty()){
            int currsum=0;
            int s=q.size();
            for(int i=0;i<s;i++){
                auto [par,child]=q.front();
                q.pop();
                int parsum=0;
                if(child->left){
                    q.push({child,child->left});
                    currsum+=child->left->val;
                    parsum+=child->left->val;
                }
                if(child->right){
                    q.push({child,child->right});
                    currsum+=child->right->val;
                    parsum+=child->right->val;
                }
                child->val=totsum-mp[par];
                mp[child]=parsum;
            }
            totsum=currsum;
        }
        return root;
    }
};
