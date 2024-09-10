class Solution {
public:
    int memo(vector<vector<int>>& dp,vector<int>& coins, int idx,int need){
        if(need==0) return 0;
        if(need<0 || idx==-1) return 1e8;
        if(dp[idx][need]!=-1) return dp[idx][need];

        int notpick=memo(dp,coins,idx-1,need);
        int pick=1e8;
        if(coins[idx]<=need) pick=1+memo(dp,coins,idx,need-coins[idx]);
        return dp[idx][need]=min(pick,notpick);

    }
    int coinChange(vector<int>& coins, int amount) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int res= memo(dp,coins,n-1,amount);
        return res==1e8?-1:res;


        // int n=coins.size();
        // vector<vector<int>> dp(n,vector<int>(amount+1,1e8));
        // for(int i=0;i<n;i++) dp[i][0]=0;
        // for(int i=1;i<=amount;i++) 
        //     if(coins[0]<=i) dp[0][i]=min(dp[0][i],1+dp[0][i-coins[0]]);
        // for(int idx=1;idx<n;idx++){
        //     for(int need=1;need<=amount;need++){
        //         int notpick=dp[idx-1][need];
        //         int pick=1e8;
        //         if(coins[idx]<=need) pick=1+dp[idx][need-coins[idx]];
        //         dp[idx][need]=min(pick,notpick);
        //     }
        // }
        // return dp[n-1][amount]==1e8?-1:dp[n-1][amount];

    }
};