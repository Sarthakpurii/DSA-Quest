class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=INT_MIN,pre=1,suf=1,n=nums.size();
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suf==0) suf=1;

            pre*=nums[i];
            suf*=nums[n-i-1];
            ans=max(ans,max(pre,suf));
        }
        return ans;
    }
};