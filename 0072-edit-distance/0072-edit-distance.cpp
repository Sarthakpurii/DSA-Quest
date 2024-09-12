class Solution {
public:
    int memo(vector<vector<int>>& dp,string& s1, string& s2, int i,int j){
        if(j==0){
            return i;
        }
        if(i==0){
            return j;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1]) return dp[i][j]=memo(dp,s1,s2,i-1,j-1);
        else{
            int insert,update,del;
            insert=memo(dp,s1,s2,i,j-1);
            update=memo(dp,s1,s2,i-1,j-1);
            del=memo(dp,s1,s2,i-1,j);
            return dp[i][j]=1+min(insert,min(update,del));
        }
    }
    int minDistance(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s1.size(),m=s2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return memo(dp,s1,s2,n,m);

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int j=1;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else{
                    int insert,update,del;
                    insert=dp[i][j-1];
                    update=dp[i-1][j-1];
                    del=dp[i-1][j];
                    dp[i][j]=1+min(insert,min(update,del));
                }
            }
        }
        return dp[n][m];

    }
};