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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int mini=INT_MAX,maxi=-1,cnt=0,pval=head->val;
        head=head->next;
        while(head->next){
            if((pval>head->val && head->val<head->next->val) ||
               (pval<head->val && head->val>head->next->val)){
                break;
            }
            pval=head->val;
            head=head->next;
        }
        pval=head->val;
        head=head->next;
        while(head && head->next){
            cnt++;
            if((pval>head->val && head->val<head->next->val) ||
               (pval<head->val && head->val>head->next->val)){
                mini=min(mini,cnt);
                maxi+=cnt;
                cnt=0;
            }
            pval=head->val;
            head=head->next;
        }
        if(mini==INT_MAX) mini=-1;
        if(maxi>-1) maxi++;
        return vector<int>{mini,maxi};
    }
};
