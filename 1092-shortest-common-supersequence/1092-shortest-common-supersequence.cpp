class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int i=n,j=m;
        string lcs;
        while(i && j){
            if(s1[i-1]==s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                lcs.push_back(s1[i-1]);
                i--;
            } 
            else {
                lcs.push_back(s2[j-1]);
                j--;
            }
        }

        while(i--) lcs.push_back(s1[i]);
        while(j--) lcs.push_back(s2[j]);

        reverse(lcs.begin(),lcs.end());
        return lcs;
    }
};