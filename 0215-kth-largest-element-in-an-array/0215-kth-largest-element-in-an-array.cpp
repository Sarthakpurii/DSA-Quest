class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<int> pq(arr.begin(),arr.end());
        k--;
        while(k--){
            pq.pop();
        }
        return pq.top();
    }
};