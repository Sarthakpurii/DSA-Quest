class Solution {
public:
    int time=0;
    void dfs(int node,int parent,vector<bool>& vis, vector<int>&lowtime,vector<int>& instime,const vector<vector<int>>& grid,vector<vector<int>>& ans){
        vis[node]=true;
        lowtime[node]=instime[node]=time++;
        for(auto i:grid[node]){
            if(i!=parent){
                if(!vis[i]){
                    dfs(i,node,vis,lowtime,instime,grid,ans);
                    lowtime[node]=min(lowtime[node],lowtime[i]);
                    if(lowtime[i]>instime[node]) ans.push_back({i,node});
                    
                }
                else lowtime[node]=min(lowtime[node],lowtime[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& conn) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //tarzan
        vector<vector<int>> grid(n),ans;
        vector<int> lowtime(n),instime(n);
        vector<bool> vis(n,false);

        for(auto v:conn){
            grid[v[0]].push_back(v[1]);
            grid[v[1]].push_back(v[0]);
        }

        dfs(0,-1,vis,lowtime,instime,grid,ans);
        
        return ans;

    }
};