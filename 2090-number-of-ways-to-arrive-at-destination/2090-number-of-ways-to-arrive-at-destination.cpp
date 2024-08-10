class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int mod=1e9+7;
        vector<vector<pair<int,int>>> grid(n);
        vector<long long> cost(n,LONG_MAX);
        vector<int> ways(n);
        cost[0]=0;
        ways[0]=1;
        long long ansVal=LONG_MAX;
        priority_queue<tuple<long long,int>,vector<tuple<long long,int>>,greater<>> pq;

        for(auto v:roads){
            grid[v[0]].push_back({v[1],v[2]});
            grid[v[1]].push_back({v[0],v[2]});
        }
        pq.push({0,0});

        while(!pq.empty()){
            auto[dist,node]=pq.top();
            pq.pop();
            if(dist>cost[n-1]) break;
            if(dist>cost[node]) continue;
            for(auto[neigh,travel]:grid[node]){
                if(dist+travel<cost[neigh]){
                    cost[neigh]=dist+travel;
                    ways[neigh]=ways[node];
                    pq.push({cost[neigh],neigh});
                }
                else if(dist+travel==cost[neigh]){
                    ways[neigh]=(ways[neigh]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};