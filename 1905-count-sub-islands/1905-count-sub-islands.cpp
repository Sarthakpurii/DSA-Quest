class Solution {
public:
    vector<int> dx={-1,0,1,0},dy={0,1,0,-1};
    int n,m;
    bool dfs(vector<vector<int>> & grid1,vector<vector<int>>& grid2,int x,int y){
        grid2[x][y]=2;
        bool status=false; // note I am taking the status in reverse manner (false:no mismatch till now, true: mismatch occured and island should not be considered)
        for(int i=0;i<4;i++){
            int tempx=x+dx[i],tempy=y+dy[i];
            if(tempx>-1 && tempx<n && tempy>-1 && tempy<m && grid2[tempx][tempy]==1){
                if(grid1[tempx][tempy]!=1){
                    status=true;
                } 
                status=dfs(grid1,grid2,tempx,tempy) || status;
            }
        }
        return status;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        n=grid2.size(),m=grid2[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1){
                    if(!dfs(grid1,grid2,i,j) && grid1[i][j]==1){
                        // cout<<i<<" "<<j<<endl;
                        ans++;
                    }
                    // else{
                    //     grid2[i][j]=2;
                    // }
                }
            }
        }
        return ans;
    }
};