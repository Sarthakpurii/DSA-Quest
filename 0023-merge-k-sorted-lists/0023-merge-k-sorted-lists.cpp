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
    struct HeapNode{
        int arr;
        ListNode* node;
        HeapNode(ListNode* v,int a): node(v),arr(a){}
        
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        auto comp=[](HeapNode& n1,HeapNode& n2){ return n1.node->val>n2.node->val;};
        priority_queue<HeapNode,vector<HeapNode>,decltype(comp)> pq(comp);
        int k=lists.size();
        ListNode* ans=new ListNode();
        ListNode* head=ans;

        for(int i=0;i<k;i++){
            if(lists[i] != nullptr) pq.push(HeapNode(lists[i],i));
        }

        while(!pq.empty()){
            HeapNode temp=pq.top();
            pq.pop();

            ans->next=temp.node;
            ans=ans->next;
        
            if(temp.node->next!=nullptr){
                pq.push(HeapNode(temp.node->next,temp.arr));
            }
        }
        return head->next;
    }
};
