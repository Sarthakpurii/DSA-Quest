class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& curr,vector<int>& cand,int remain, int idx){
        if(remain==0){
            ans.push_back(curr);
            return;
        }
        
        if(remain<0 || idx==cand.size()) return;
        for(int i=idx;i<cand.size();i++){
            if(i!=idx && cand[i]==cand[i-1]) continue;
            curr.push_back(cand[i]);
            helper(ans,curr,cand,remain-cand[i],i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(cand.begin(),cand.end());
        // set<vector<int>> ans;
        vector<int> curr;
        vector<vector<int>>  ans;
        helper(ans,curr,cand,target,0);
        return ans;
    }
};
