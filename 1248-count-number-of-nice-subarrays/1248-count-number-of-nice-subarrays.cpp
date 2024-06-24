class Solution {
public:
    int atmost(vector<int> nums,int k){
        if(k<0) return 0;
        int r=0,l=0,ans=0,curr=0,n=nums.size();
        while(r<n){
            if(nums[r]&1) curr++;
            while(curr>k) if(nums[l++]&1) curr--;
            if(curr<=k) ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};