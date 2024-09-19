class Solution {
public:
    // int memo(int i,int j,vector<int>& cuts, vector<vector<int>>& dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int mini=INT_MAX;
    //     for(int k=i;k<=j;k++){
    //         int val=cuts[j+1]-cuts[i-1]+memo(i,k-1,cuts,dp)+memo(k+1,j,cuts,dp);
    //         mini=min(mini,val);
    //     }
    //     return dp[i][j]=mini;
    // }
    int minCost(int n, vector<int>& cuts) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c=cuts.size();
        // vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        // return memo(1,c-2,cuts,dp);

        vector<vector<int>> dp(c+1,vector<int>(c+1,0));
        for(int i=c-2;i>0;i--){
            for(int j=i;j<=c-2;j++){
                int mini=INT_MAX;
                for(int k=i;k<=j;k++){
                    int val=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                    mini=min(mini,val);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c-2];
    }
};