class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int currMax=0,globalMax=INT_MIN;
        for(int n:nums){
            currMax=max(currMax+n,n);
            globalMax=max(globalMax,currMax);
        }
        return globalMax;
    }
};