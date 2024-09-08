// class Solution {
// public:

//     long long findMaximumScore(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         int n=nums.size();
//         vector<long long> dp(n,-1);
//         dp[0]=0;
//         for(int i=1;i<n;i++){
//             long long maxi=-1;
//             for(int j=i-1;j>-1;j--){
//                 long long value=(long long)nums[j]*(i-j)+dp[j];
//                 maxi=max(maxi,value);
//             }
//             dp[i]=maxi;
//         }
//         return dp[n-1];
//     }
// };

class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int ans = 0;
        int l = nums[0];
        int j = 0;

        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] > nums[j]) {
                ans += l * (i - j);
                l = nums[i];
                j = i;
            }
        }

        ans += l * (n - 1 - j);
        return ans;
    }
};