class Solution {
public:
int n,k;
    int memo(int days,int city,vector<vector<int>>& stay, vector<vector<int>>& travel,vector<vector<int>>& dp){
        if(days==k-1) return dp[days][city]=max(stay[k-1][city],*max_element(travel[city].begin(), travel[city].end()));
        if(dp[days][city]!=-1) return dp[days][city];
        int stayed=memo(days+1,city,stay,travel,dp)+stay[days][city];
        int travelled=0;
        for(int i=0;i<n;i++){
            int temp=memo(days+1,i,stay,travel,dp)+travel[city][i];
            travelled=max(temp,travelled);
        }
        return dp[days][city]=max(travelled,stayed);
    }
    int maxScore(int N, int K, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        n=N,k=K;
        int ans=0;
        vector<vector<int>> dp(K+1,vector<int>(N+1,-1));
        for(int i=0;i<n;i++){
            ans=max(memo(0,i,stayScore,travelScore,dp),ans);
        }
        return ans;
    }
};