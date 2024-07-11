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


//y->height
//x->breadth
class Solution {
public:
    struct cord{
        TreeNode* node;
        int x;
        int y;
        cord(TreeNode* n,int X,int Y): node(n),x(X),y(Y){};
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        stack<cord> st;
        st.push(cord(root,0,0));
        map<int,map<int,vector<int>>> data;
        // data[0][0]={root->val};

        // pair<int,int> rangex={0,0};
        while(!st.empty()){
            cord cordd=st.top();
            st.pop();
            int x=cordd.x,y=cordd.y;
            TreeNode* node=cordd.node;
            if(node->right){
                st.push(cord(node->right,x+1,y+1));
            }
            if(node->left){
                st.push(cord(node->left,x-1,y+1));
            }
            if(data.find(x)==data.end()){
                data[x][y]={node->val};
            }
            else{
                if(data[x].find(y)==data[x].end()){
                    data[x][y]={node->val};
                }
                else{
                    data[x][y].push_back(node->val);
                }
            }
        }
        for(auto outermap:data){
            vector<int> vertilevel;
            for(auto innermap:outermap.second){
                sort(innermap.second.begin(),innermap.second.end());
                vertilevel.insert(vertilevel.end(),innermap.second.begin(),innermap.second.end());
            }
            ans.push_back(vertilevel);
        }
        return ans;
    }
};