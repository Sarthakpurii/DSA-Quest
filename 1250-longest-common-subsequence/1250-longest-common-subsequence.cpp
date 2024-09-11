class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        vector<int> curr(m+1,0);

        for(int i=1;i<=n;i++){
            vector<int> temp(m+1,0);
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) temp[j]=1+curr[j-1];
                else temp[j]=max(temp[j-1],curr[j]);
            }
            curr=temp;
        }

        return curr[m];
    }
};


//tabulation

// class Solution {
// public:
//     int longestCommonSubsequence(string s1, string s2) {
//         int n=s1.size(),m=s2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));

//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
//                 else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//             }
//         }

//         return dp[n][m];
//     }
// };

//Memoization

// class Solution {
// public:
//     int memo(vector<vector<int>>& dp,string& s1, string& s2,int i,int j){
//         if(i==0 || j==0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s1[i-1]==s2[j-1]) return dp[i][j]=1+memo(dp,s1,s2,i-1,j-1);
//         return dp[i][j]=max(memo(dp,s1,s2,i-1,j),memo(dp,s1,s2,i,j-1));
//     }
//     int longestCommonSubsequence(string s1, string s2) {
//         int n=s1.size(),m=s2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//         return memo(dp,s1,s2,n,m);
//     }
// };