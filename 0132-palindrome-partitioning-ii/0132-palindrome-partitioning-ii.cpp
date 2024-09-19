class Solution {
public:
    int n=2001;
    
    bool ispalin(int i,int j,string & s,vector<vector<int>>& pdp){
        if(pdp[i][j]!=-1) return pdp[i][j];
        int ci=i,cj=j;
        while(i<j){
            if(s[i++]!=s[j--]) return pdp[ci][cj]=false;
            if(pdp[i][j]!=-1) return pdp[ci][cj]=pdp[i][j];
        }
        return pdp[ci][cj]=true;
    }
    int memo(int i,string& s,vector<int>& dp,vector<vector<int>>& pdp){
        if(ispalin(i,s.size()-1,s,pdp)) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<s.size();k++){
            if(ispalin(i,k,s,pdp)){
                ans=min(ans,memo(k+1,s,dp,pdp));
            }
        }
        return dp[i]=ans+1;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> pdp(n,vector<int>(n,-1));
        vector<int> dp(n,-1);
        return memo(0,s,dp,pdp);
    }
};

// n^3
// class Solution {
// public:
//     bool ispalin(string& s,int i,int j,vector<vector<int>>& palindp){
//         if(palindp[i][j]!=-1) return palindp[i][j];
//         int ci=i,cj=j;
//         while(i<j){
//             if(s[i++]!=s[j--]) return palindp[ci][cj]=false;
//             if(palindp[i][j]!=-1) return palindp[ci][cj]=palindp[i][j];
//         }
//         return palindp[ci][cj]=true;
//     }

//     int memo(int i,int j,string& s, vector<vector<int>>& dp,vector<vector<int>>& palindp){
//         if(ispalin(s,i,j,palindp)) return 0; 
//         if(dp[i][j]!=-1) return dp[i][j];
//         // if(ispalin(s,i,j)) return 0;
//         int mini=INT_MAX;
//         for(int k=i;k<j;k++){
//             int cuts=1+memo(i,k,s,dp,palindp)+memo(k+1,j,s,dp,palindp);
//             mini=min(cuts,mini);
//         }
//         return dp[i][j]=mini;
//     }
//     int minCut(string s) {
//         int j=s.size()-1;
//         vector<vector<int>> dp(j+1,vector<int>(j+1,-1));
//         vector<vector<int>> palindp(j+1,vector<int>(j+1,-1));
//         return memo(0,j,s,dp,palindp);
        
//     }
// };