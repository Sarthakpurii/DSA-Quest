class Solution {
public:
    vector<pair<int,int>> delta={{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(vector<vector<int>>& grid,int x,int y){
        int n=grid.size();
        grid[x][y]=2;
        for(int i=0;i<4;i++){
            int dx=x+delta[i].first,dy=y+delta[i].second;
            if(dx>-1 && dx<n && dy>-1 && dy<n && grid[dx][dy]==0) dfs(grid,dx,dy);
        }
    }
    int regionsBySlashes(vector<string>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0,n=grid.size();
        // vector<vector<int>> empty={{0,0,0},{0,0,0},{0,0,0}},slash={{0,0,1},{0,1,0},{1,0,0}},bslash={{1,0,0},{0,1,0},{0,0,1}};
        vector<vector<int>> final(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    final[i*3][j*3+2]=1;
                    final[i*3+1][j*3+1]=1;
                    final[i*3+2][j*3]=1;
                }
                else if(grid[i][j]=='\\'){
                    final[i*3][j*3]=1;
                    final[i*3+1][j*3+1]=1;
                    final[i*3+2][j*3+2]=1;
                }
            }
        }
        // 
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(final[i][j]==0){
                    dfs(final,i,j);
                    ans++;
                }  
            }
        }


        return ans;
    }
};