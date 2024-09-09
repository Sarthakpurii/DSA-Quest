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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int rbound=n,lbound=-1,ubound=0,dbound=m,i=0,j=0;

        while(head){
            while(j<rbound){
                if(!head) break;
                ans[i][j++]=head->val;
                head=head->next;
            }
            rbound--;
            j--;
            i++;
            while(i<dbound){
                if(!head) break;
                ans[i++][j]=head->val;
                head=head->next;
            }
            dbound--;
            i--;
            j--;
            while(j>lbound){
                if(!head) break;
                ans[i][j--]=head->val;
                head=head->next;
            }
            lbound++;
            j++;
            i--;
            while(i>ubound){
                if(!head) break;
                ans[i--][j]=head->val;
                head=head->next;
            }
            ubound++;
            i++;
            j++;
        }
        return ans;
    }
};