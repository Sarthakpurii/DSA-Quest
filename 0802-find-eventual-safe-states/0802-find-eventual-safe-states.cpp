class Solution {
public:
    bool dfs(const vector<vector<int>>& graph,vector<int>& vis,vector<int>& path,vector<int>& ans, int i){
        // if(path[i]) return false;
        vis[i]=1;
        path[i]=1;
        for(const int j: graph[i]){
            if(path[j]) return false;
            if(!vis[j]) if(!dfs(graph,vis,path,ans,j)) return false;
        }
        path[i]=0;
        ans.push_back(i);
        return true;
    }
    vector<int> eventualSafeNodes(const vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=graph.size();
        vector<int> vis(n,0),path(n,0),ans;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,vis,path,ans,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};