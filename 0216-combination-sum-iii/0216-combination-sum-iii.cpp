class Solution {
public:
    void helper(vector<vector<int>>& ans,vector<int>& curr,int remain,int nUsed,int start){
        if(!remain && !nUsed){
            ans.push_back(curr);
            return;
        }
        if(remain<0 || nUsed<0) return;
        for(int i=start;i<10;i++){
            curr.push_back(i);
            helper(ans,curr, remain-i,nUsed-1,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans;
        vector<int> curr;
        helper(ans,curr,n,k,1);
        return ans;
    }
};