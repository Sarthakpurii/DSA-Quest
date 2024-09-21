class Solution {
public:
    int mem(int i,int target,vector<vector<int>>& dp){
        if(i==1) return target;
        if(dp[i][target]!=-1) return dp[i][target];
        int pick=1e7;
        if(target>=(i*i)) pick=1+mem(i,target-(i*i),dp);
        int npick=mem(i-1,target,dp);
        return dp[i][target]=min(pick,npick);

    }
    int numSquares(int n) {
        int sq=sqrt(n);
        vector<vector<int>> dp(sq+1,vector<int>(n+1,-1));
        return mem(sq,n,dp);
    }
};