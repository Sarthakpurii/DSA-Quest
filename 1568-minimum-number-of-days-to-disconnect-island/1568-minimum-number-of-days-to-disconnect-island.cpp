class Solution {
public:
    vector<int> dx{1,0,-1,0},dy={0,1,0,-1};
    int time=0,nodes=0;
    void dfs(vector<vector<int>>& grid,int i,int j){
        grid[i][j]=2;
        nodes++;
        for(int k=0;k<4;k++){
            int x=dx[k]+i,y=dy[k]+j;
            if(x>-1 && y>-1 && x<grid.size() && y<grid[0].size() && grid[x][y]==1){
                dfs(grid,x,y);
            }
        }
    }
    bool tarjan(pair<int,int> idx,pair<int,int> parent,vector<vector<int>>& grid,vector<vector<int>>& lowtime,vector<vector<int>>& instime){
        auto [i,j]=idx;
        auto [pi,pj]=parent;
        grid[i][j]=3;
        lowtime[i][j]=instime[i][j]=time++;
        for(int k=0;k<4;k++){
            int x=dx[k]+i,y=dy[k]+j;
            if(x>-1 && y>-1 && x<grid.size() && y<grid[0].size()){
                if (x == pi && y == pj) continue; //go through
                if(grid[x][y]==2){
                    if(tarjan({x,y},{i,j},grid,lowtime,instime)) return true;
                    lowtime[i][j]=min(lowtime[i][j],lowtime[x][y]);
                    if(instime[i][j]<lowtime[x][y]) return true;
                }
                else if(grid[x][y]==3) lowtime[i][j]=min(lowtime[i][j],lowtime[x][y]);
            }
        }
        return false;
    }
    int minDays(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> lowtime(n,vector<int>(m,INT_MAX)),instime(n,vector<int>(m,INT_MAX));
        bool onefound=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if(onefound) return 0;
                    onefound=true;
                    dfs(grid,i,j);
                }
            }
        }

        // for(auto v:grid){
        //     for( auto w:v) cout<<w<<" ";
        //     cout<<endl;
        // }
        if(!onefound) return 0;
        if(nodes==2) return 2;
        if(nodes==1) return 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    if(tarjan({i,j},{-1,-1},grid,lowtime,instime))return 1;
                    // for(auto v:instime){
                    //     for( auto w:v) cout<<w<<" ";
                    //     cout<<endl;
                    // }
                    // for(auto v:lowtime){
                    //     for( auto w:v) cout<<w<<" ";
                    //     cout<<endl;
                    // }
                    return 2;
                }
            }
        }
        return -1;
    }
};