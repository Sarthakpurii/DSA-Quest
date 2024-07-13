/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        ostringstream oss;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* temp=st.top();
            st.pop();
            if(!temp){
                oss<<"N,";
                continue;
            }
            oss<<temp->val<<',';
            if(temp->right) st.push(temp->right);
            else st.push(nullptr);
            if(temp->left) st.push(temp->left);
            else st.push(nullptr);
        }
        return oss.str();
    }
    string nextElement(stringstream &ss){
        string token;
        if(getline(ss,token,','))
        return token;
        return "";
    }
    TreeNode* build(stringstream& ss){
        string token=nextElement(ss);
        if(token=="" || token=="N") return nullptr;
        TreeNode* root=new TreeNode(stoi(token));
        root->left=build(ss);
        root->right=build(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));