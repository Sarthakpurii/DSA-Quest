class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size(),r=n-1,l=0,ans=0;
        while(l<k){
            ans+=nums[l++];
        }
        l--;
        int temp=ans;
        while(l>=0){
            temp=temp-nums[l--]+nums[r--];
            ans=max(ans,temp);
        }
        return ans;
    }
};