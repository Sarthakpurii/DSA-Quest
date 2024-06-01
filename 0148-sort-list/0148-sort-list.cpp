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
    ListNode *middleFinder(ListNode *head){
        ListNode *fast=head,*slow=head;
        while(fast->next and fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode *mergeFunc(ListNode *l1,ListNode *l2){
        ListNode* temp=new ListNode(-1);
        ListNode *curr=temp;
        while(l1 and l2){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1) temp->next=l1;
        else temp->next=l2;
        return curr->next;
    }
    ListNode *mergeSort(ListNode *head){
        if(!head || !head->next) return head;
        ListNode *middle=middleFinder(head);
        ListNode *left=head;
        ListNode *right=middle->next;
        middle->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        return mergeFunc(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};