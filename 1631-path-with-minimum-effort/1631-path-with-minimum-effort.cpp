class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=heights.size(),m=heights[0].size();
        vector<pair<int,int>> delta={{0,1},{0,-1},{1,0},{-1,0}};
        auto cmp=[](vector<int>& v1, vector<int>& v2){
            return v1[0]>v2[0];
        };
        priority_queue<vector<int>,vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({0,0,0});
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        cost[0][0]=0;
        
        while(!pq.empty()){
            int dist=pq.top()[0],x=pq.top()[1],y=pq.top()[2];
            pq.pop();
            for(int i=0;i<4;i++){
                int dx=x+delta[i].first,dy=y+delta[i].second;
                if(dx>-1 && dx<n && dy>-1 && dy<m && 
                cost[dx][dy]>max(dist,abs(heights[x][y]-heights[dx][dy]))){
                    cost[dx][dy]=max(dist,abs(heights[x][y]-heights[dx][dy]));
                    pq.push({cost[dx][dy],dx,dy});
                }
            }
        }
        return cost[n-1][m-1];

    }
};