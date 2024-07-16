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
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* curr;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
        curr=st.top();
        st.pop();
    }
    
    int next() {
        int val=curr->val;
        curr=curr->right;
        while(curr){
            st.push(curr);
            curr=curr->left;
        }
        if(!st.empty()){
            curr=st.top();
            st.pop();
        }else curr=nullptr;
        return val;
    }
    
    bool hasNext() {
        if(curr) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */