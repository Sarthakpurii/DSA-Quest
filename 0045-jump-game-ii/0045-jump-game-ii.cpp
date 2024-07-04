class Solution {
public:
    int jump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int currfar=0,ans=0,i=0,n=nums.size(),currrange=0;
        if(n==1) return ans;
        for(;i<n;i++){
            if(currrange<i){
                currrange=currfar;
                ans++;
            }
            currfar=max(currfar,i+nums[i]);
            if(currrange>=n-1) return ans;
        }
        return ans;
    }
};