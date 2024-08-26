// //memoization
// class Solution {
// public:
//     int n;
//     int memo(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j){
//         if(dp[i][j]!=INT_MAX) return dp[i][j];
//         int up=INT_MAX,rdiag=INT_MAX,ldiag=INT_MAX;
//         if(j+1<n) rdiag=memo(grid,dp,i-1,j+1);
//         if(j>0) ldiag=memo(grid,dp,i-1,j-1);
//         up=memo(grid,dp,i-1,j);
//         return dp[i][j]=grid[i][j]+min(up,min(rdiag,ldiag));

//     }
//     int minFallingPathSum(vector<vector<int>>& grid) {
        // n=grid.size();
        // vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        // for(int i=0;i<n;i++){
        //     dp[0][i]=grid[0][i];
        // }
//         int ans=INT_MAX;
//         for(int i=0;i<n;i++){
//             ans=min(ans,memo(grid,dp,n-1,i));
//         }
//         return ans;
//     }
// };

//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=INT_MAX,rdiag=INT_MAX,ldiag=INT_MAX;
                if(j+1<n) rdiag=dp[i-1][j+1];
                if(j>0) ldiag=dp[i-1][j-1];
                up=dp[i-1][j];
                dp[i][j]=grid[i][j]+min(up,min(rdiag,ldiag));
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
        
    }
};