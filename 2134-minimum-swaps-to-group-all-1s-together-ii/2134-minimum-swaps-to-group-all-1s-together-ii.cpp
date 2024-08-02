class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size(),ones=count(nums.begin(),nums.end(),1),curr=0,ans=INT_MIN;
        for(int i=0;i<ones;i++) curr+=nums[i];
        ans=max(curr,ans);
        for(int i=0;i<n-1;i++){
            curr=curr-nums[i]+nums[(i+ones)%n];
            ans=max(curr,ans);
        }
        return ones-ans;
    }
};