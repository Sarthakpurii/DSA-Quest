class Solution {
public:
    int bitscalc(int num){
        int ans=0;
        while(num){
            ans+=(num&1);
            num>>=1;
        }
        return ans;
    }                                                 
    bool canSortArray(vector<int>& nums) {
        // cout<<bitscalc(30);
        int maxf=nums[0],maxs=-1,fb=-1,sb=-1,i=1,n=nums.size();
        fb=bitscalc(nums[0]);
        while(i<n && bitscalc(nums[i])==fb){
            maxf=max(maxf,nums[i]);
            i++;
        }
        while(i<n){
            sb=bitscalc(nums[i]);
            // cout<<maxf;
            while(i<n && bitscalc(nums[i])==sb){
                if(maxf>nums[i]){
                // cout<<maxf<<" "<<nums[i];
                return false;
                } 
                maxs=max(maxs,nums[i]);
                i++;
            }
            maxf=maxs;
            maxs=-1;
        }
        return true;
    }
};