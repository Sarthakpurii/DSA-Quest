class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& cand,vector<int>& curr, int remain,int idx){
        if(remain==0){
            ans.push_back(curr);
            return;
        }
        if(idx==cand.size() || remain<0) return;
        curr.push_back(cand[idx]);
        helper(ans,cand,curr,remain-cand[idx],idx);
        curr.pop_back();
        helper(ans,cand,curr,remain,idx+1);        
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans,cand,curr,target,0);
        return ans;
    }
};