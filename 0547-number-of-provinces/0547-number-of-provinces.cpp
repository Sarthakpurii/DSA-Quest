class Solution {
public:
    void dfs(const vector<vector<int>>&conn,vector<int>& vis,int start,const int &n){
        vis[start]=1;
        for(int i=0;i<n;i++){
            if(vis[i]==0 && conn[start][i]){
                dfs(conn,vis,i,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& conn) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=conn.size(),ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                dfs(conn,vis,i,n);
            }
        }
        return ans;
    }
};