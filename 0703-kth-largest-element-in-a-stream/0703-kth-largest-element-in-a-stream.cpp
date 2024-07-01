class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i:nums) pq.push(i);
    }
    
    int add(int val) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        pq.push(val);
        while(pq.size()!=K) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//  class KthLargest {
// public:
//     stack<int> st;
//     priority_queue<int> pq;
//     int K;
//     KthLargest(int k, vector<int>& nums) {
//         for(int i:nums) pq.push(i);
//         K=k;
//     }
    
//     int add(int val) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         while(!st.empty() && st.top()<val){
//             pq.push(st.top());
//             st.pop();
//         }
//         pq.push(val);
//         for(int i=st.size();i<K;i++){
//             st.push(pq.top());
//             pq.pop();
//         }
//         return st.top();
//     }
// };

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */