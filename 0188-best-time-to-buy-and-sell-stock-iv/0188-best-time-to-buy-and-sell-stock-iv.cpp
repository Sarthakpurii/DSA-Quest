class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(4,0));
        // return memo(dp,prices,0,4);

        vector<int> prev(2*k+1,0);
        for(int i=n-1;i>-1;i--){
            vector<int> curr(2*k+1,0);
            for(int buy=1;buy<=2*k;buy++){
                if(buy%2==0){
                    curr[buy]=max(prev[buy],-prices[i]+prev[buy-1]);
                }
                else curr[buy]=max(prev[buy],prices[i]+prev[buy-1]);
            }
            prev=curr;
        }
        return prev[2*k];

    }
};
// class Solution {
// public:
    
//     int maxProfit(int k, vector<int>& prices) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int n=prices.size();
//         // vector<vector<int>> dp(n,vector<int>(4,0));
//         // return memo(dp,prices,0,4);

//         vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
//         for(int i=n-1;i>-1;i--){
//             for(int buy=1;buy<=2*k;buy++){
//                 if(buy%2==0){
//                     dp[i][buy]=max(dp[i+1][buy],-prices[i]+dp[i+1][buy-1]);
//                 }
//                 else dp[i][buy]=max(dp[i+1][buy],prices[i]+dp[i+1][buy-1]);
//             }
//         }
//         return dp[0][2*k];

//     }
// };