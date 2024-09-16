class Solution {
public:
    int n;
    int memo(vector<vector<int>>& dp,vector<int>& nums,int i,int prev){
        if(i==n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int take=0;
        if(prev==0 || nums[i]>nums[prev-1]) take=1+memo(dp,nums,i+1,i+1);
        int nottake=memo(dp,nums,i+1,prev);
        return dp[i][prev]=max(take,nottake);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return memo(dp,nums,0,0);

        vector<vector<int>> dp(n+1,vector<int>(n+2,0));
        for(int i=n-1;i>-1;i--){
            for(int prev=n;prev>-1;prev--){
                int take=0;
                if(prev==0 || nums[i]>nums[prev-1]) take=1+dp[i+1][i+1];
                int nottake=dp[i+1][prev];
                dp[i][prev]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
};