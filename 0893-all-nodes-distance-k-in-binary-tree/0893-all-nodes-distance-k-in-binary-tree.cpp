/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> mp;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left){
                mp[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                mp[temp->right]=temp;
                q.push(temp->right);
            }
        }

        unordered_set<TreeNode*> visited={target};
        q.push(target);
        vector<int> ans;
        int curr=0;
        while(!q.empty() && curr<k){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && visited.find(temp->left)==visited.end()){
                    q.push(temp->left);
                    visited.insert(temp->left);
                }
                if(temp->right && visited.find(temp->right)==visited.end()){
                    q.push(temp->right);
                    visited.insert(temp->right);
                }
                if(mp.find(temp)!=mp.end() && visited.find(mp[temp])==visited.end()){
                    q.push(mp[temp]);
                    visited.insert(mp[temp]);
                }
            }
            curr++;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;

    }
};