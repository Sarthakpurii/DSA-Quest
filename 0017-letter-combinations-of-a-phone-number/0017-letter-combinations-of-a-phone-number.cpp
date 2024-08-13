class Solution {
public:
    vector<string> mp={"ac","df","gi","jl","mo","ps","tv","wz"};
    void helper(vector<string>& ans,string& curr,string& dig,int idx){
        if(idx==dig.size()){
            ans.push_back(curr);
            return;
        }
        string range=mp[dig[idx]-'2'];
        for(char c=range[0];c<=range[1];c++){
            curr.push_back(c);
            helper(ans,curr,dig,idx+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> ans;
        if(!digits.size()) return ans;
        string curr;
        helper(ans,curr,digits,0);
        return ans;
    }
};