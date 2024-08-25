// class Solution {
// public:
//     int memo(vector<vector<int>>& grid, vector<vector<int>>& dp,int i,int j){
//         if(dp[i][j]!=INT_MAX) return dp[i][j];
//         int left=INT_MAX,up=INT_MAX;
//         if(j-1>-1) left=memo(grid,dp,i,j-1);
//         if(i-1>-1) up=memo(grid,dp,i-1,j);
//         return dp[i][j]=grid[i][j]+min(left,up);
//     }
//     //tabulation
//     int minPathSum(vector<vector<int>>& grid) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int n=grid.size(),m=grid[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
//         dp[0][0]=grid[0][0];
//         // return memo(grid,dp,n-1,m-1);
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(i==0&&j==0) continue;
//                 int left=INT_MAX,up=INT_MAX;
//                 if(j-1>-1) left=dp[i][j-1];
//                 if(i-1>-1) up=dp[i-1][j];
//                 dp[i][j]=grid[i][j]+min(left,up);
//             }
//         }
        
//         return dp[n-1][m-1];
//     }
// };

//Memory optimized solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size(),m=grid[0].size();
        vector<int> prev(m,INT_MAX);
        prev[0]=grid[0][0];
        for(int j=1;j<m;j++){
            prev[j]=grid[0][j]+prev[j-1];
        }
        for(int i=1;i<n;i++){
            vector<int> curr(m,INT_MAX);
            for(int j=0;j<m;j++){
                int left=INT_MAX, up=INT_MAX;
                up= prev[j];
                if(j-1>-1) left=curr[j-1];
                curr[j]=grid[i][j]+min(left,up);
            }
            prev=curr;
        }
        return prev[m-1];
    }
};