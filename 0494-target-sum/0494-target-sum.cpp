class Solution {
public:
    int tar;
    int start;
    int memo(vector<vector<int>>& dp,vector<int>& nums,int curr, int idx){
        if(idx==-1){
            if(tar==curr) return 1;
            return 0;
        }
        if(dp[idx][start+curr]!=-1) return dp[idx][start+curr];
        int pos=memo(dp,nums,curr+nums[idx],idx-1);
        int neg=memo(dp,nums,curr-nums[idx],idx-1);
        
        return dp[idx][curr+start]=pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // tar=target;
        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0);
        // start=sum;
        // vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        // return memo(dp,nums,0,n-1);

        vector<vector<int>> dp(n,vector<int>(2*sum+1,0));
        dp[0][sum+nums[0]]=1;
        dp[0][sum-nums[0]]+=1;
        if(target>sum || target<-sum) return 0;
        for(int idx=1;idx<n;idx++){
            for(int curr=-sum;curr<=sum;curr++){
                int pos=0,neg=0;
                if(curr+nums[idx]<=sum) pos=dp[idx-1][curr+nums[idx]+sum];
                if(curr-nums[idx]>=-sum) neg=dp[idx-1][curr-nums[idx]+sum];
                
                dp[idx][curr+sum]=pos+neg;
            }
        }
        // for(int idx=0;idx<n;idx++){
        //     for(int curr=-sum;curr<=sum;curr++){
        //         cout<<dp[idx][curr+sum]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n-1][sum+target];
    }
};