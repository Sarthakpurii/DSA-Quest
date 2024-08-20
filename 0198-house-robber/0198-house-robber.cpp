class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int p2=nums[0],p1=max(p2,nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(nums[i]+p2,p1);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int n=nums.size();
//         if(n==1) return nums[0];
//         vector<int> dp(n,0);
//         dp[0]=nums[0],dp[1]=nums[1];
//         if(n>2) dp[2]=dp[0]+nums[2];
//         for(int i=3;i<n;i++){
//             dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
//         }
//         return max(dp[n-1],dp[n-2]);
//     }
// };