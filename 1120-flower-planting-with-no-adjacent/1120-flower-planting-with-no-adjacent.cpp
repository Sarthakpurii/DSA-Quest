class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<int>& vis,int i){
        for(int f=1;f<5;f++){
            vis[i]=f;
            bool condi=true;
            for(auto child:grid[i]){
                if(vis[child]==f){
                    condi=false;
                    break;
                }
            }
            if(!condi) continue;
            for(auto child:grid[i]){
                if(vis[child]==-1) dfs(grid,vis,child);
            }
            break;
        }
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> vis(n,-1);
        vector<vector<int>> grid(n,vector<int>());
        for(auto i:paths){
            grid[i[0]-1].push_back(i[1]-1);
            grid[i[1]-1].push_back(i[0]-1);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1) dfs(grid,vis,i);
        }
        return vis;
    }
};