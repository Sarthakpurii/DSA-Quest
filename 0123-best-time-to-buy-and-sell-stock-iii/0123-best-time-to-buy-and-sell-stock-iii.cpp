class Solution {
public:
    int n;
    int memo(vector<vector<int>>& dp,vector<int>& prices, int i,int buy){
        if(buy==0) return 0;
        if(i==n) return 0;
        if(dp[i][buy-1]!=-1) return dp[i][buy-1];
        if(buy%2==0){
            return dp[i][buy-1]=max(memo(dp,prices,i+1,buy),-prices[i]+memo(dp,prices,i+1,buy-1));
        }
        else{
            return dp[i][buy-1]=max(memo(dp,prices,i+1,buy),prices[i]+memo(dp,prices,i+1,buy-1));
        }
    }
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(4,0));
        // return memo(dp,prices,0,4);

        vector<vector<int>> dp(n+1,vector<int>(5,0));
        for(int i=n-1;i>-1;i--){
            for(int buy=1;buy<=4;buy++){
                if(buy%2==0){
                    dp[i][buy]=max(dp[i+1][buy],-prices[i]+dp[i+1][buy-1]);
                }
                else dp[i][buy]=max(dp[i+1][buy],prices[i]+dp[i+1][buy-1]);
            }
        }
        return dp[0][4];

    }
};