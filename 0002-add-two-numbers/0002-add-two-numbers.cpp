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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sol=new ListNode(-1),*temp1=l1,*temp2=l2;
        ListNode *temp3=sol;
        int ans=0;
        while(temp1 and temp2){
            ans+=temp1->val+temp2->val;
            temp3->next=new ListNode(ans%10);
            ans/=10;
            temp1=temp1->next;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        while(temp1){
            ans+=temp1->val;
            temp3->next=new ListNode(ans%10);
            ans/=10;
            temp1=temp1->next;
            temp3=temp3->next;
        }
        while(temp2){
            ans+=temp2->val;
            temp3->next=new ListNode(ans%10);
            ans/=10;
            temp2=temp2->next;
            temp3=temp3->next;
        }
        if(ans%10>0) temp3->next=new ListNode(1);
        return sol->next;

    }
};
