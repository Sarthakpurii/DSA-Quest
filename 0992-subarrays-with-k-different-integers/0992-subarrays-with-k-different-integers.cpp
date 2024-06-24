class Solution {
public:
    int atmost(vector<int> nums, int k){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(k<0) return 0;
        int r=0,l=0,n=nums.size(),ans=0;
        unordered_map<int,int> mapp;
        while(r<n){
            mapp[nums[r]]++;
            while(mapp.size()>k){
                mapp[nums[l]]--;
                if(mapp[nums[l]]==0) mapp.erase(nums[l]);
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};