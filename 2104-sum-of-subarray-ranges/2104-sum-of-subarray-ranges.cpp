class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        long long sol=0;
        for(int i=0;i<n-1;i++){
            int minn=min(nums[i],nums[i+1]);
            int maxx=max(nums[i],nums[i+1]);
            sol+=maxx-minn;
            for(int j=i+2;j<n;j++){
                minn=min(nums[j],minn);
                maxx=max(nums[j],maxx);
                sol+=maxx-minn;
            }
        }
        return sol;
    }
};