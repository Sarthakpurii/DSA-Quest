class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size(),maxi=1,si=0;
        vector<int> dp(n,1),hash(n);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<1+dp[j]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                si=i;
            }
        }
        for(int i:dp) cout<<i<<" ";
        cout<<endl;
        for(int i:hash) cout<<i<<" ";
        vector<int> ans;
        ans.push_back(nums[si]);
        while(hash[si]!=si){
            si=hash[si];
            ans.push_back(nums[si]);
        }
        return ans;
    }
};