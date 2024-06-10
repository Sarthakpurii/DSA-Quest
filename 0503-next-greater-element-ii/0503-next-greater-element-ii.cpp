class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=2*n-1;i>-1;i--){
            while(!st.empty() && st.top()<=nums[i%n]) st.pop();
            if(!st.empty()){
                ans[i%n]=st.top();
            }
                st.push(nums[i%n]);
        }
        return ans;

    }
};