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
    ListNode *reverseKNodes(ListNode* head,int k){
        ListNode* curr=head,*prev=nullptr;
        while(k--){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;            
        }
        return prev;
    }
    ListNode* reverseGroup(ListNode* head, int k){
        int K=k;
        bool endReached=false;
        ListNode* end=head;
        while(K--){
            if(!end){
                endReached=true;
                break;     
            }
            end=end->next;
        }
        if(endReached) return head;
        ListNode* newh=reverseKNodes(head,k);
        head->next=reverseGroup(end,k);
        return newh;        
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        //Recursive
        if(!head or !head->next or k==1) return head;
        return reverseGroup(head,k);

    }
};