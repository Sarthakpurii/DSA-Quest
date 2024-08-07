class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size(),ans=0;
        if(n==1) return (grid[0][0])?-1:1;
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=-1;
        vector<pair<int,int>> delta={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
        while(!q.empty()){
            ans++;
            int s=q.size();
            while(s--){
                auto [x,y]=q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int dx=x+delta[i].first,dy=y+delta[i].second;
                    if(dx>-1 && dx<n && dy>-1 && dy<n && grid[dx][dy]==0){
                        if(dx==n-1 && dy==n-1) return ans+1;
                        q.push({dx,dy});
                        grid[dx][dy]=-1;
                    }
                }
            }
        }
        return -1;
        
    } 
};