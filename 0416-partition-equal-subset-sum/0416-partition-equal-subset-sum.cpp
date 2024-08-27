class Solution {
public:
    // bool memo(vector<int>& nums,vector<vector<int>>& dp,int s1,int s2,int idx){

    //     if(idx==0) return (s1==s2+nums[0])||(s2==s1+nums[0]);
    //     bool left=memo(nums,dp,s1+nums[idx],s2,idx-1);
    //     bool right=memo(nums,dp,s1,s2+nums[idx],idx-1);
    //     return left||right;
    // }
    bool canPartition(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size(),sum=0;
        for(const auto& i:nums) sum+=i;
        if(sum&1) return false;
        sum/=2;
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=nums[i]) dp[i][j]=dp[i][j] || dp[i-1][j-nums[i]];
                dp[i][j]=dp[i][j] || dp[i-1][j];
            }
        }
        return dp[n-1][sum];
    }
};