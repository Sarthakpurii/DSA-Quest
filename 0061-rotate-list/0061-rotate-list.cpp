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
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(!head) return head;
        int cnt=0;
        ListNode *temp=head,*fast=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        // cout<<cnt<<endl;
        k=k%cnt;
        // cout<<k;
        temp=head;
        while(k--) fast=fast->next;
        while(fast->next){
            fast=fast->next;
            temp=temp->next;
        }
        fast->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};