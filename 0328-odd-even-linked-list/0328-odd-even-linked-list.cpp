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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next or !head->next->next) return head;
        ListNode* temp=head->next->next;
        ListNode* odd=head->next;
        ListNode* even=head;
        ListNode* oddCopy=odd;
        ListNode* evenCopy=even;
        int cnt=0;
        while(temp){
            if(cnt%2==0){
                even->next=temp;
                even=even->next;
            }else{
                odd->next=temp;
                odd=odd->next;
            }
            temp=temp->next;
            cnt++;
        }
        odd->next=NULL;
        even->next=oddCopy;
        return evenCopy;
    }
};