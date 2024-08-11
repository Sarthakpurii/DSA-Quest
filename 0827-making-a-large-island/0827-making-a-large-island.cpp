class DisjointSet{
    public:
    vector<int> parent,sizee;
    DisjointSet(int n){
        sizee.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int ultParent(int n){
        if(parent[n]==n) return n;
        return parent[n]=ultParent(parent[n]);
    }
    

    void unionSize(int i,int j,int &ans){
        int pi=ultParent(i),pj=ultParent(j);
        if(pi==pj) return;
        if(sizee[pi]<sizee[pj]){
            parent[pi]=pj;
            sizee[pj]+=sizee[pi];
            ans=max(ans,sizee[pj]);
        }
        else{
            parent[pj]=pi;
            sizee[pi]+=sizee[pj];
            ans=max(ans,sizee[pi]);
        }
    }
    
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=grid.size(),m=grid[0].size();
        DisjointSet s(n*m);
        vector<int> dx={1,0,-1,0},dy={0,1,0,-1};
        int ans=1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=2;k<4;k++){
                        int x=i+dx[k],y=j+dy[k];
                        if(x>-1 && x<n && y>-1 && y<m && grid[x][y]==1){
                            s.unionSize(i*m+j,x*m+y,ans);
                        }
                    }
                }
            }
        }
        // for(auto i:s.sizee) cout<<i<<" ";
        // cout<<endl;
        // for(auto i:s.parent) cout<<i<<" ";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    // cout<<"hello"<<" ";
                    unordered_set<int> sett;
                    for(int k=0;k<4;k++){
                        int x=i+dx[k],y=j+dy[k];
                        if(x>-1 && x<n && y>-1 && y<m && grid[x][y]==1){
                            sett.insert(s.ultParent(x*m+y));
                        }
                    }
                    int temp=0;
                    for(auto elem:sett) temp+=s.sizee[elem];
                    ans=max(++temp,ans);
                }
            }
        }
        return ans;
    }
};