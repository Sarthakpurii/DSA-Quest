class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for (int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if (nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {};
    }
};