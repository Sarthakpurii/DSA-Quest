class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> grid(n,vector<int>());
        vector<int> indeg(n,0),ans;
        for(auto i:prereq){
            grid[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        } 
        queue<int> q;
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
        while(!q.empty()){
            int elem=q.front();
            q.pop();
            ans.push_back(elem);
            for(const int &i:grid[elem]) if(--indeg[i]==0) q.push(i);
        }
        return (ans.size()==n);
    }
};