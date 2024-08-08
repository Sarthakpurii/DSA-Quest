class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        k=k-1;
        vector<int> ans(n,INT_MAX);
        vector<vector<pair<int,int>>> grid(n);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        for(auto v:times) grid[v[0]-1].push_back({v[1]-1,v[2]});
        
        ans[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [cost,node]=pq.top();
            pq.pop();
            if(cost>ans[node]) continue;
            for(auto[neigh,price]:grid[node]){
                if(ans[neigh]>cost+price){
                    ans[neigh]=cost+price;
                    pq.push({ans[neigh],neigh});
                }
            }
        }
        
        int miniTime=INT_MIN;
        for(auto i:ans) miniTime=max(miniTime,i);
        return (miniTime==INT_MAX)?-1:miniTime;

    }
};