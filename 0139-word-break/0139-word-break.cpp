class Solution {
public:
    bool memo(int i,int j, string& s, unordered_set<string>& st,vector<vector<int>>& dp){
        if(i==0){
            return dp[i][j]=(st.find(s.substr(0,j+1))!=st.end());
        }
        if(dp[i][j]!=-1) return dp[i][j];
        bool skip=memo(i-1,j,s,st,dp);
        bool pick=false;
        if(st.find(s.substr(i,j-i+1))!=st.end()){
            pick=memo(i-1,i-1,s,st,dp);
        }
        return dp[i][j]=(pick || skip);
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return memo(n-1,n-1,s,st,dp);
    }
};