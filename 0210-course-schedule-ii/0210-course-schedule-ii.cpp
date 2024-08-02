class Solution {
public:
    bool dfs(vector<int>& ans,vector<int>& vis,vector<int>& path,const vector<vector<int>>& grid,int idx){
        vis[idx]=1;
        path[idx]=1;
        for(int i:grid[idx]){
            if(path[i]==1) return false;
            if(vis[i]==1) continue;
            if(!dfs(ans,vis,path,grid,i)) return false;
        }
        ans.push_back(idx);
        path[idx]=0;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prereq) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans,vis(n,0),path(n,0);
        vector<vector<int>> courses(n,vector<int>());
        for(auto i:prereq) courses[i[0]].push_back(i[1]);
        // for(auto i:courses){
        //     for(auto j:i) cout<<j<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(!dfs(ans,vis,path,courses,i)) return vector<int>();
            }
        }
        return ans;
    }
};