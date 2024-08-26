/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//recursive 
// class Solution {
// public:
//     void post(vector<int>& ans,Node* root){
//         for(auto i:root->children){
//             post(ans,i);
//         }
//         ans.push_back(root->val);
//     }
//     vector<int> postorder(Node* root) {
//         vector<int> ans;
//         if(!root) return ans;
//         post(ans,root);
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> postorder(Node* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans;
        if(!root) return ans;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* temp=st.top();
            st.pop();
            for(auto i:temp->children){
                st.push(i);
            }
            ans.push_back(temp->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};