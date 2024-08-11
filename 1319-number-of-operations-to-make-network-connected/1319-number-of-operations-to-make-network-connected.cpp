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
    int makeConnected(int n, vector<vector<int>>& conn) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        DisjointSet s(n);
        int exwires=0,needed=0;
        for(auto i: conn){
            if(s.ultParent(i.front())!=s.ultParent(i.back())){
                s.unionSize(i[0],i[1]);
            }
            else exwires++;
        }
        for(int i=1;i<n;i++){
            if(s.ultParent(0)!=s.ultParent(i)){
                s.unionSize(0,i);
                if(!exwires) return -1;
                exwires--;
                needed++;
            }
        }
        return needed;
        
    }
};