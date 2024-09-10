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
    int gcd(int a,int b){
        if(!a) return b;
        b%=a;
        if(!b) return a;
        a%=b;
        return gcd(a,b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev=head,*temp=head;
        temp=temp->next;
        while(temp){
            ListNode* gc=new ListNode(gcd(prev->val,temp->val));
            prev->next=gc;
            gc->next=temp;
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};