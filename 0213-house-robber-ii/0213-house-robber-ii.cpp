class Solution {
public:
    int robbingExpert(vector<int>& nums, int idx){
        int n=nums.size();
        int p2=nums[idx],p1=max(nums[idx],nums[idx+1]);
        for(int i=idx+2;i<n-!idx;i++){
            int curr=max(nums[i]+p2,p1);
            p2=p1;
            p1=curr;
        }
        return p1;
    }
    int rob(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(robbingExpert(nums,0),robbingExpert(nums,1));
    }
};