// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// public:
//     ListNode* h;
//     bool helper(ListNode* head,TreeNode* root,bool original){
//         if(!head) return true;
//         if(!root) return false;
//         // cout<<head->val<<" "<<c<<endl;
//         if(head->val==root->val){
//             if(helper(head->next,root->left,original)) return true;
//             if(helper(head->next,root->right,original)) return true;
//         }
//         else if(original){
//             if(helper(h,root->left,original)) return true;
//             if(helper(h,root->right,original)) return true;
//         }
//         if(head!=h && h->val==root->val){
//             if(helper(h->next,root->left,false)) return true;
//             if(helper(h->next,root->right,false)) return true;
//         }
//         return false;
//     }
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         h=head;
//         return helper(head,root,true);
//     }
// };
class Solution{
    public:
    bool dfs(ListNode*head,TreeNode* root){
        if(!head) return true;
        if(!root) return false;
        if(root->val!=head->val) return false;
        return dfs(head->next,root->left) || dfs(head->next,root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root){
        if(!root) return false;
        return dfs(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};
// class Solution {
// public:
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         return searchForPath(head, head, root);
//     }
// private:
//     bool searchForPath(ListNode* pathStart, ListNode* currentNode, TreeNode* treeNode) {
//         if (currentNode == nullptr) {
//             return true;
//         }
//         if (treeNode == nullptr) {
//             return false;
//         }
        
//         if (currentNode->val == treeNode->val) {
//             currentNode = currentNode->next;
//         } else if (pathStart->val == treeNode->val) {
//             pathStart = pathStart->next;
//         } else {
//             currentNode = pathStart;
//         }
        
//         return searchForPath(pathStart, currentNode, treeNode->left) || 
//                searchForPath(pathStart, currentNode, treeNode->right);
//     }
// };
// static const int kds = []() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     return 0;
// }();

//Kartikdevsharmaa