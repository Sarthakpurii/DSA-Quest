// //memoization
// class Solution {
// public:
//     int memo(vector<vector<int>>& dp,vector<vector<int>>& triangle,int i,int j){
//         if(dp[i][j]!=INT_MAX) return dp[i][j];
//         int up=INT_MAX,diag=INT_MAX; 
//         if(j!=i) up=memo(dp,triangle,i-1,j);
//         if(j>0) diag=memo(dp,triangle,i-1,j-1);
//         return dp[i][j]=triangle[i][j]+min(up,diag);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>> dp;
//         for(int i=0;i<n;i++){
//             dp.push_back(vector<int>(i+1,INT_MAX));
//         }
//         dp[0][0]=triangle[0][0];
//         int ans=INT_MAX;
//         for(int i=0;i<n;i++){
//             ans=min(ans,memo(dp,triangle,n-1,i));
//         }
        
//         return ans;
        
//     }
// };
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp;
        for(int i=0;i<n;i++){
            dp.push_back(vector<int>(i+1,INT_MAX));
        }
        dp[0][0]=triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<=i;j++){
                int up=INT_MAX,diag=INT_MAX; 
                if(j!=i) up=dp[i-1][j];
                if(j>0) diag=dp[i-1][j-1];
                dp[i][j]=triangle[i][j]+min(up,diag);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};