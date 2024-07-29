class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=mat.size(),m=mat[0].size(),dist=0;
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> q;
        vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=dist;
                }
            }
        }
        cout<<q.size();
        while(!q.empty()){
            int s=q.size();
            dist++;
            for(int i=0;i<s;i++){
                auto [x,y]=q.front();
                q.pop();
                
                for(int j=0;j<4;j++){
                    int tempx=x+dx[j],tempy=y+dy[j];
                    if(tempx>-1 && tempx<n && tempy>-1 && tempy<m){
                        if(ans[tempx][tempy]==-1){
                            q.push({tempx,tempy});
                            ans[tempx][tempy]=dist;
                        }
                    }
                }
            }
        }
        return ans;
    
    }
};