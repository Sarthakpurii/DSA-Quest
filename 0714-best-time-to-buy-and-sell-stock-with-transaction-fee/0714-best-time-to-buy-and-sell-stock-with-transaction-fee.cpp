class Solution {
public:
    // int n,f;
    // int memo(vector<vector<int>>& dp,vector<int>& prices,int i,int buy){
    //     if(i>=n) return 0;
    //     if(dp[i][buy]!=-1) return dp[i][buy];
    //     if(buy) return dp[i][buy]=max(memo(dp,prices,i+1,buy),-prices[i]+memo(dp,prices,i+1,0));
    //     else return dp[i][buy]=max(memo(dp,prices,i+1,buy),-f+prices[i]+memo(dp,prices,i+1,1));
    // }
    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=prices.size();
        // f=fee;
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        // return memo(dp,prices,0,1);

        vector<vector<int>> dp(n+1,vector<int>(2,0));
        // dp[n-1][0]=prices[n-1];
        // dp[n-1][1]=max(dp[n][1],-prices[n-1]+dp[n][0]);

        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<2;buy++){
                if(buy) dp[i][buy]=max(dp[i+1][buy],-prices[i]+dp[i+1][0]);
                else dp[i][buy]=max(dp[i+1][buy],-fee+prices[i]+dp[i+1][1]);
            }
        }
        return dp[0][1];
    }
};