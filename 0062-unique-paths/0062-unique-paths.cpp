//space optimized dp tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        prev[0]=1;
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(j>0) temp[j]=temp[j-1]+prev[j];
                else temp[j]=prev[j];
            }
            prev=temp;
        }
        return prev[n-1];
        
    }
};

//tabulation

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         dp[0][0]=1;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(i==0 && j==0) continue;
//                 else{
//                     int up=0,left=0;
//                     if(i-1>-1) up=dp[i-1][j];
//                     if(j-1>-1) left=dp[i][j-1];
//                     dp[i][j]=up+left;
//                 }
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };

//memoization
// class Solution {
// public:
//     int helper(vector<vector<int>>& dp,int m,int n){
//         if(n==0 && m==0) return dp[m][n]=1;
//         if(dp[m][n]!=-1) return dp[m][n];
//         int up=0,left=0;
//         if(m-1>-1) up=helper(dp,m-1,n);
//         if(n-1>-1) left=helper(dp,m,n-1);
//         return dp[m][n]=up+left;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         helper(dp,m-1,n-1);
//         return dp[m-1][n-1];
//     }
// };