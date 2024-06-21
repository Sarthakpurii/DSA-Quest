class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int i=0,j=0,n=nums.size(),ans=0;
        while(j<n){
            if(nums[j]==0){
                if(k>0){
                    k--;
                }
                else{
                    while(i<n && nums[i]!=0) i++;
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};