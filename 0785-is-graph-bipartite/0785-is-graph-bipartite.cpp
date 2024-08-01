class Solution {
public:
    bool dfs(const vector<vector<int>>& graph,vector<int>& vis,int curr,int currcolor){
        vis[curr]=currcolor;
        for(int i:graph[curr]){
            if(vis[i]==-1){
                if(!dfs(graph,vis,i,1-currcolor)) return false;
            }
            else if(vis[i]==vis[curr]) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(graph,vis,i,0)) return false;
            }
        }
        return true;
    }
};