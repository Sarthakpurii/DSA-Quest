class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        struct hash_func{
            size_t operator()(const pair<int,int> & p) const {
                size_t h1=hash<int>{}(p.first);
                size_t h2=hash<int>{}(p.second);
                return h1^h2;
            }
        };
        unordered_set<pair<int,int>,hash_func> obst;
        for(auto v:obstacles) obst.insert({v[0],v[1]});
        
        vector<int> xaxis={0,1,0,-1},yaxis={1,0,-1,0};
        int ans=0;
        int x=0,y=0,dir=0,n=com.size();
        for(int i=0;i<n;i++){
            if(com[i]==-1) dir=(dir+1)%4;
            else if(com[i]==-2){
                if(dir==0) dir=3;
                else dir--;
            }
            else{
                int temp=com[i];
                // bool obsfound=false;
                while(temp--){
                    int tempx=x+xaxis[dir],tempy=y+yaxis[dir];
                    if(obst.find({tempx,tempy})!=obst.end()) break;
                    x=tempx;
                    y=tempy;
                }
                ans=max(ans,x*x+y*y);
            }
            
        }
        cout<<x<<" "<<y;
        return ans;
    }
};