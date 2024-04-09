class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int low=INT_MIN,high=0;
        for(int i:nums){
            high+=i;
            if(low<i) low=i;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int nSubarr=divideSubarray(nums,k,mid);
            if(nSubarr>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
private:
    int divideSubarray(vector<int> nums,int k,int space){
        int nSubarr=1,tspace=space;
        for(int i:nums){
            if(tspace<i){
                nSubarr++;
                tspace=space;
            }
            tspace-=i;
            if(nSubarr>k) return k+1;
        }
        return nSubarr;
    }
};