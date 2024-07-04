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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* newhead=new ListNode();
        ListNode* nh=newhead;
        int tot=0;
        head=head->next;
        while(head){
            if(head->val==0){
                ListNode* temp=new ListNode(tot);
                tot=0;
                nh->next=temp;
                nh=nh->next;
            }
            else{
                tot+=head->val;
            }
            head=head->next;
        }
        return newhead->next;
        
    }
};