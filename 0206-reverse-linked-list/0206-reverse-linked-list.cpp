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

    ListNode* reverseList(ListNode* head) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        //Iterative: 

        // ListNode* prev=NULL,*temp=head;
        // while(temp!=NULL){
        //     ListNode* front=temp->next;
        //     temp->next=prev;
        //     prev=temp;
        //     temp=front;
        // }
        // return prev;

        //Recursive:

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newh=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newh;
    }
};