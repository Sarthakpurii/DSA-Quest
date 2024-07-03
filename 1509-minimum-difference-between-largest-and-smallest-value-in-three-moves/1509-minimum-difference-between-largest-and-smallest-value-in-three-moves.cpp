class Solution {
public:
    int minDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(nums.size()<5) return 0;
        sort(nums.begin(),nums.end());
        int ans=INT_MAX,k=nums.size()-4;
        for(int i=0;i<4;i++){
            ans=min(ans,nums[k++]-nums[i]);
        }
        return ans;
    }
};