#include <algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            long hrs=hrsReq(piles,mid);
            // cout<<hrs<<" ";
            if(hrs>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }

private:
    long hrsReq(vector<int> nums,int rate){
        long hrs=0;
        for(int i:nums){
            hrs+=ceil(i/(double)rate);
        }
        return hrs;
    }
};
