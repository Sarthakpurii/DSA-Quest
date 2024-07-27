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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> sett(nums.begin(),nums.end());
        ListNode* node=head;
        ListNode* ans=nullptr;
        bool ini=true;
        while(node){
            if(sett.find(node->val)==sett.end()){
                if(ini){
                    head=node;
                    ans=node;
                    ini=false;
                    node=node->next;
                }
                else{
                    ans->next=node;
                    ans=ans->next;
                    node=node->next;
                }
            }
            else{
                node=node->next;
            }
        }
        ans->next=nullptr;
        return head;
    }
};