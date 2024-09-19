class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size(),maxi=1,maxcount=0;
        vector<int> dp(n,1),countt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(dp[i]-1==dp[j]) countt[i]+=countt[j];
                if(nums[i]>nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    countt[i]=countt[j];
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                maxcount=countt[i];
            }
            else if(maxi==dp[i]){
                maxcount+=countt[i];
            }

        }
        for(int i: dp) cout<<i<<" ";
        cout<<endl;
        for(int i: countt) cout<<i<<" ";
        return maxcount;
        
    }
};