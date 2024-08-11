class DisjointSet{
    vector<int> parent,sizee;
    public:
    DisjointSet(int n){
        sizee.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int ultParent(int n){
        if(parent[n]==n) return n;
        return parent[n]=ultParent(parent[n]);
    }

    void unionSize(int i,int j){
        int pi=ultParent(i),pj=ultParent(j);
        if(pi==pj) return;
        if(sizee[pi]<sizee[pj]){
            parent[pi]=pj;
            sizee[pj]+=sizee[pi];
        }
        else{
            parent[pj]=pi;
            sizee[pi]+=sizee[pj];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size();
        DisjointSet s(n*n);
        map<int,vector<pair<int,int>>> mp;
        vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]].push_back({i,j});
            }
        }

        for(auto [i,v]:mp){
            for(auto [x,y]:v){
                for(int k=0;k<4;k++){
                    int nx=x+dx[k],ny=y+dy[k];
                    if(nx>-1 && nx<n && ny>-1 && ny<n && grid[nx][ny]<=i){
                        s.unionSize(x*n+y,nx*n+ny);
                    }
                }
            }
            if(s.ultParent(0)==s.ultParent(n*n-1)) return i;
        }
        return -1;
    }
};