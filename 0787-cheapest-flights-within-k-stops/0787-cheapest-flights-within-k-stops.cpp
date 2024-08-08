class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<tuple<int,int,int>> q;
        vector<vector<pair<int,int>>> grid(n);
        vector<int> cost(n,INT_MAX);

        for(auto v:flights) grid[v[0]].push_back({v[1],v[2]});
        
        q.push({0,0,src});
        while(!q.empty()){
            auto [stop,currCost,node]=q.front();
            q.pop();
            if(cost[node]>currCost) cost[node]=currCost;
            if(stop>k) continue;
            for(auto [neigh,price]:grid[node]){
                if(currCost+price<cost[neigh]) q.push({stop+1,currCost+price,neigh});
            }
        }
        return (cost[dst]==INT_MAX)?-1:cost[dst];
    }
};

//Dijkstra cant be applied, modified can be applied  but will take more time due to push and pop log n ops resulting in TLE

// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         // vector<int> cost(n,INT_MAX);
//         vector<vector<pair<int,int>>> grid(n);
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

//         for(auto v:flights){
//             grid[v[0]].push_back({v[1],v[2]});
//             // grid[v[1]].push_back({v[0],v[2]});
//         }
//         // for(auto v:grid){
//         //     for(auto i:v) cout<<i.first<<"-"<<i.second<<" ";
//         //     cout<<endl;
//         // }
//         pq.push({0,{0,src}});
//         // cost[src]=0;
        
//         while(!pq.empty()){
//             auto [costTillNow,p]=pq.top();
//             auto [K,node]=p;
//             pq.pop();
//             // cout<<costTillNow<<" "<<K<<" "<<node<<endl;
//             // cout<<endl;
//             if(node==dst) return costTillNow;
//             // if(K>k) continue;
//             // if(cost[node]<costTillNow) continue;
//             for(auto i:grid[node]){
//                 if(K<=k) pq.push({costTillNow+i.second,{K+1,i.first}});
//             }
//             // cout<<endl;
//         }
//         // for(int i:cost) cout<<i<<" ";
//         return -1;
//     }

// };