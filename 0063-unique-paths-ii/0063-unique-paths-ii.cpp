class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return 0;
        vector<vector<unsigned long>> dp(m,vector<unsigned long>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=1;
                else{
                    if(grid[i][j]==1) dp[i][j]=0;
                    else{
                        unsigned long up=0,left=0;
                        if(i>0) up=dp[i-1][j];
                        if(j>0) left=dp[i][j-1];
                        dp[i][j]=up+left;
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//memoization;
// class Solution {
// public:
//     int helper(vector<vector<int>>& dp,vector<vector<int>>& grid, int m,int n){
//         if(dp[m][n]!=-1) return dp[m][n];
//         if(grid[m][n]==1) return dp[m][n]=0;
//         if(n==0 && m==0) return dp[m][n]=1;
//         int up=0,left=0;
//         if(m-1>-1) up=helper(dp,grid,m-1,n);
//         if(n-1>-1) left=helper(dp,grid,m,n-1);
//         return dp[m][n]=up+left;
//     }
//     int uniquePathsWithObstacles(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         if(grid[0][0]==1 || grid[m-1][n-1]) return 0;
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         return helper(dp,grid,m-1,n-1);
//     }
// };