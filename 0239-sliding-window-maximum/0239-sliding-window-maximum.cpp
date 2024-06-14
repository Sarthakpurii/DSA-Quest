class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        vector<int> ans(n-k+1,0);
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
        }
        ans[0]=nums[dq.front()];
        for(int i=k;i<n;i++){
            if(i-dq.front()>=k) dq.pop_front();
            while(!dq.empty() && nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            ans[i-k+1]=nums[dq.front()];
        }
        return ans;
    }
};