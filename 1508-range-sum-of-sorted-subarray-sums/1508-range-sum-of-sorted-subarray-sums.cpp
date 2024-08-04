class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> sum;
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=i;j<n;j++){
                ans+=nums[j];
                sum.push_back(ans);
            }
        }
        sort(sum.begin(),sum.end());
        int res=0,mod=1e9+7;
        for(int i=left-1;i<right;i++){
            res=(res+sum[i])%mod;
        }
        return res;
    }
};