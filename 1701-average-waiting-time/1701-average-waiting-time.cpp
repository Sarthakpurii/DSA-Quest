class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int currtime=0,n=customers.size();
        double ans=0;
        for(int i=0;i<n;i++){
            if(currtime<=customers[i][0]){
                ans+=customers[i][1];
                currtime=customers[i][0]+customers[i][1];
            }
            else{
                currtime+=customers[i][1];
                ans+=currtime-customers[i][0];
            }
        }
        return ans/n;
    }
};