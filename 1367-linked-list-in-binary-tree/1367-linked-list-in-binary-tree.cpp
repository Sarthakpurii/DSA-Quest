/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* h;
    bool helper(ListNode* head,TreeNode* root,bool original){
        if(!head) return true;
        if(!root) return false;
        // cout<<head->val<<" "<<c<<endl;
        if(head!=h && h->val==root->val){
            if(helper(h->next,root->left,false)) return true;
            if(helper(h->next,root->right,false)) return true;
        }
        if(head->val==root->val){
            if(helper(head->next,root->left,original)) return true;
            if(helper(head->next,root->right,original)) return true;
        }
        else if(original){
            if(helper(h,root->left,original)) return true;
            if(helper(h,root->right,original)) return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        h=head;
        return helper(head,root,true);
    }
};