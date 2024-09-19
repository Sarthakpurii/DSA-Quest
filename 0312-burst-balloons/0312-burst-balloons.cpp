class Solution {
public:
    int memo(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            maxi=max(maxi,nums[i-1]*nums[k]*nums[j+1]+memo(i,k-1,nums,dp)+memo(k+1,j,nums,dp));
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n=nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // return memo(1,n-2,nums,dp);

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-2;i>0;i--){
            for(int j=i;j<n-1;j++){
                int maxi=INT_MIN;
                for(int k=i;k<=j;k++){
                    maxi=max(maxi,nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n-2];
    }
};