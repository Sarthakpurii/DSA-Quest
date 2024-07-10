class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int cap) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(trips.begin(),trips.end(),[](vector<int> &v1,vector<int> &v2){
            return v1[1]<v2[1];
        });
        int n=trips.size(),i=0,currcap=0;
        while(i<n){
            if(pq.empty()){
                pq.push({trips[i][2],trips[i][0]});
                currcap+=trips[i][0];
                if(currcap>cap) return false;
                i++;
            }
            else{
                if(pq.top().first<=trips[i][1]){
                    currcap-=pq.top().second;
                    pq.pop();
                }
                else{
                    pq.push({trips[i][2],trips[i][0]});
                    currcap+=trips[i][0];
                    if(currcap>cap) return false;
                    i++;
                }
            }
        }
        return true;
    }
};