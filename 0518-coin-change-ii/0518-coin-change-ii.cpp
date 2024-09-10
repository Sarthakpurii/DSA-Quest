class Solution {
public:
    int memo(vector<vector<int>>& dp,vector<int>& coins, int idx,int need){
        if(need==0) return 1;
        if(need<0 || idx==-1) return 0;
        if(dp[idx][need]!=-1) return dp[idx][need];

        int notpick=memo(dp,coins,idx-1,need);
        int pick=0;
        if(coins[idx]<=need) pick=memo(dp,coins,idx,need-coins[idx]);
        return dp[idx][need]=pick+notpick;

    }
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return memo(dp,coins,n-1,amount);
    }
};