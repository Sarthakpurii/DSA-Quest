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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head or !head->next) return NULL;
        int idx=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            idx++;
        }
        cout<<idx;
        idx=idx-n;
        cout<<idx;
        if(idx==0){
            head=head->next;
            return head;
        }
        temp=head;
        for(int i=1;i<idx ;i++){
            cout<<i;
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};