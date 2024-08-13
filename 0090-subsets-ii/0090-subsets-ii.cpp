class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int start){
        ans.push_back(curr);
        for(int i=start;i<nums.size();i++){
            if(i!=start &&nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            helper(ans,nums,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans,nums,curr,0);
        return ans;
    }
};