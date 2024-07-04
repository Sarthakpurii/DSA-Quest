class Solution {
public:
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int currFarthest=0,i=0,n=nums.size();
        for(;i<n;i++){
            if(i>currFarthest) return false;
            currFarthest=max(currFarthest,i+nums[i]);
            if(currFarthest>=n) return true;
        }
        return true;
    }
};