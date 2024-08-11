class Solution {
public:
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
        if(pi>pj){
            parent[pi]=pj;
            // sizee[pj]+=sizee[pi];
        }
        else{
            parent[pj]=pi;
            // sizee[pi]+=sizee[pj];
        }
        // for(auto i:parent) cout<<i;
        // cout<<endl;
    }
    
};
    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string,int> mp;
        int n =acc.size(),c=0;
        DisjointSet s(n);
        vector<vector<string>> ans;
        vector<int> idx(n,-1);

        for(int i=0;i<n;i++){
            for(int j=1;j<acc[i].size();j++){
                if(mp.find(acc[i][j])==mp.end()){
                    mp[acc[i][j]]=i;
                }
                else{
                    int p=s.ultParent(mp[acc[i][j]]);
                    s.unionSize(p,i);
                }
            }
        }
        // for(auto i:s.parent) cout<<i;
        for(int i=0;i<n;i++){
            int p=s.ultParent(i);
            if(i==p){
                idx[i]=c;
                ans.push_back({acc[i][0]});
                for(int j=1;j<acc[i].size();j++){
                    if(mp[acc[i][j]]!=-1){
                        ans[idx[p]].push_back(acc[i][j]);
                        mp[acc[i][j]]=-1;
                    }
                }
                c++;
            }
            else{
                for(int j=1;j<acc[i].size();j++){
                    if(mp[acc[i][j]]!=-1){
                        ans[idx[p]].push_back(acc[i][j]);
                        mp[acc[i][j]]=-1;
                    }
                    // idx[i]=idx[p];
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin()+1,ans[i].end());
        }
        
        
        return ans;
    }
};