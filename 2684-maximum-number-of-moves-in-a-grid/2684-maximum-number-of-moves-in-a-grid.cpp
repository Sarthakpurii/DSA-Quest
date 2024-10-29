class Solution {
public:
    int m,n;
    int memo(vector<vector<int>>& grid,int cidx,int ridx,vector<vector<int>>& dp){
        if(cidx==n-1) return cidx;
        if(dp[ridx][cidx]!=-1) return dp[ridx][cidx];
        int left=cidx,center=cidx,right=cidx;
        if(ridx>0 && grid[ridx][cidx]<grid[ridx-1][cidx+1]) left=memo(grid,cidx+1,ridx-1,dp);
        if(grid[ridx][cidx]<grid[ridx][cidx+1]) center=memo(grid,cidx+1,ridx,dp);
        if(ridx<m-1 && grid[ridx][cidx]<grid[ridx+1][cidx+1]) right=memo(grid,cidx+1,ridx+1,dp);
        return dp[ridx][cidx]=max(left,max(right,center));
    }

    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(memo(grid,0,i,dp),ans);
        }
        return ans;
    }
};