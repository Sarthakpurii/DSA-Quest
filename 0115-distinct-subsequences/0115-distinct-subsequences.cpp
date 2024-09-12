class Solution {
public:
    int numDistinct(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        if(n<m) return 0;
        vector<double> dp(m+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s1[i-1]==s2[j-1]) dp[j]=(dp[j]+dp[j-1]);
                
            }
        }
        return (int)dp[m];
        
    }
};

// class Solution {
// public:
//     int findlcs(vector<vector<int>>& dp, string& s1,string& s2,
//      int i,int j,vector<vector<int>>& vis){
//         if(i==0 || j==0){
//             // reverse(curr.begin(),curr.end());
//             // cout<<"hel;lo";
//             return 1;
//         }
//         // string key=to_string(i)+" "+to_string(j);
//         // if(vis.find(key)!=vis.end()) return vis[key];
//         // vis.insert(key);
//         if(vis[i][j]!=-1) return vis[i][j];
//         int match=0,umatch=0,lmatch=0;
//         if(s1[i-1]==s2[j-1]) match=findlcs(dp,s1,s2,i-1,j-1,vis);
        
//         if(dp[i][j]==dp[i-1][j]) umatch=findlcs(dp,s1,s2,i-1,j,vis);
//         if(dp[i][j]==dp[i][j-1]) lmatch=findlcs(dp,s1,s2,i,j-1,vis);
//         return vis[i][j]=match+umatch+lmatch;
        
//     }
    
    
//     int numDistinct(string s1, string s2) {
//         int n=s1.size(),m=s2.size();
//         if(n<m) return 0;
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         vector<vector<int>> vis(n+1,vector<int>(m+1,-1));

//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
//                 else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
//             }
//         }

//         // for(int i=0;i<=n;i++){
//         //     for(int j=0;j<=m;j++){
//         //         cout<<dp[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }
//         if(dp[n][m]!=m) return 0;
//         return findlcs(dp,s1,s2,n,m,vis);
//     }
// };