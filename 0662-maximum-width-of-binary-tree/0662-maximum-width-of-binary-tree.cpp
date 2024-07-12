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
    int widthOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unsigned long long ans=1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,1});
        while(!q.empty()){
            int s=q.size();
            unsigned long long mini = ULLONG_MAX, maxi = 0;
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front().first;
                unsigned long long curr=q.front().second;
                q.pop();
                if(temp->left) q.push({temp->left,2*curr});
                if(temp->right) q.push({temp->right,2*curr+1});
                mini=min(mini,curr);
                maxi=max(maxi,curr);
            }
            ans=max(ans,maxi-mini+1);
        }
        return ans;
    }
};