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
    int countValid(){
        int c=0;
        for(int i=0;i<parent.size();i++){
            if(ultParent(parent[i])==i && sizee[i]>1) c++;
        }
        return c;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int maxrow=0,maxcol=0;
        
        for(auto v:stones){
            maxrow=max(maxrow,v[0]);
            maxcol=max(maxcol,v[1]);
        }
        DisjointSet s(maxrow+maxcol+1);
        
        // unordered_set<int> stonesNodes;
        for(auto v:stones){
            s.unionSize(v[0],maxrow+1+v[1]);
            // stonesNodes.insert(v[0]);
            // stonesNodes.insert(v[1]+maxrow+1);
        }
        // int c=0;
        // for(auto i:stonesNodes) if(s.ultParent(i)==i) c++;
        // return stones.size()-c;
        return stones.size()-s.countValid();
        
    }
};