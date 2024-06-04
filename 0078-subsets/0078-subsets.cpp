class Solution {
public:
    void helper(vector<vector<int>>& sol,vector<int> curr,vector<int> nums,int idx,int n){
        if(idx==n){
            sol.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        helper(sol,curr,nums,idx+1,n);
        curr.pop_back();
        helper(sol,curr,nums,idx+1,n);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> sol;
        helper(sol,{},nums,0,nums.size());
        return sol;
    }
};