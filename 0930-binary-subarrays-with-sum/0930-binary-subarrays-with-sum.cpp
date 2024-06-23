class Solution {
public:
    int atmost(vector<int> nums,int goal){
        if(goal<0) return 0;
        int r=0,l=0,ans=0,sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>goal && l<nums.size()){
                sum-=nums[l++];
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};