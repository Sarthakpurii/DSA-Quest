class Solution {
public:
    bool check(vector<int>& start, long mid,int d){
        int n=start.size();
        long temp=start[0];
        for(int i=1;i<n;i++){
            temp=max(temp+mid,(long)start[i]);
            if(temp>start[i]+d) return false;
        }
        return true;
    }
    int maxPossibleScore(vector<int>& start, int d) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(start.begin(),start.end());
        long low=0,high=start.back()-start.front()+d;
        while(low<=high){
            long mid=low+(high-low)/2;
            if(check(start,mid,d)) low=mid+1;
            else high=mid-1;
        }
        return high;

    }
};