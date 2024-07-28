class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size(),ans=-1;
        bool normal=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                // if(grid[i][j]==1){
                //     normal=true;
                    // if normal is unreachable
                //     if ((i-1<0 || grid[i-1][j]==0) && (i+1>=n || grid[i+1][j]==0)
                //  && (j-1<0 || grid[i][j-1]==0) && (j+1>=m || grid[i][j+1]==0)) return -1;
                // }
            }
        }
        //if normal exist and no rotten exist, normal will stay normal;
        // cout<<q.size();
        // if(q.empty() && normal) return -1;
        while(!q.empty()){
            int s=q.size();
            ans++;
            for(int k=0;k<s;k++){
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i-1>=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                }
                if(i+1<n && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                }
                if(j-1>=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                }
                if(j+1<m && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        if(ans==-1) return 0;
        // if the ans is still -1 it means there were no normal and q must have been empty so 0 minutes
        return ans;
    }
};