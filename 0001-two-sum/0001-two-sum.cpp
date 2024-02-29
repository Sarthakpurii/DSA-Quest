class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n=nums.size();
        unordered_map<int,int> mapped;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(mapped.find(rem)!=mapped.end()){
                return {mapped[rem],i};
            }
            mapped[nums[i]]=i;
        }
        return {};
    }
};