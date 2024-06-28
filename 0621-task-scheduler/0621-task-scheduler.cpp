class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> mapp(26,0);
        for(auto c:tasks) mapp[c-'A']++;
        priority_queue<int> pq;
        for(int i:mapp) if(i!=0) pq.push(i);
        queue<pair<int,int>> q;
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()){
                int val=pq.top()-1;
                pq.pop();
                if(val!=0) q.push({val,time+n+1});
            }
        }
        return time;
    }
};