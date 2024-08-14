class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& curr,vector<bool>& taken,vector<int>& nums){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(taken[i]) continue;
            taken[i]=true;
            curr.push_back(nums[i]);
            helper(ans,curr,taken,nums);
            taken[i]=false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> taken(nums.size(),false);
        helper(ans,curr,taken,nums);
        return ans;
    }
};