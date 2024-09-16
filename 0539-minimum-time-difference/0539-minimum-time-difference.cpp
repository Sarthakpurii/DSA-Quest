class Solution {
public:
    int findMinDifference(vector<string>& time) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=time.size();
        sort(time.begin(),time.end());
        int diff=INT_MAX;
        for(int i=0;i<n-1;i++){
            int hdiff=stoi(time[i+1].substr(0,2))-stoi(time[i].substr(0,2));
            int mdiff=stoi(time[i+1].substr(3,2))-stoi(time[i].substr(3,2));
            diff=min(diff,hdiff*60+mdiff);
        }
        int hdiff=23-stoi(time[n-1].substr(0,2))+stoi(time[0].substr(0,2));
        int mdiff=60-stoi(time[n-1].substr(3,2))+stoi(time[0].substr(3,2));
        diff=min(diff,hdiff*60+mdiff);
        
        return diff;
    }
};