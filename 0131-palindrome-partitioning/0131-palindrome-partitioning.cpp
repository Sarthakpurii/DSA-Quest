class Solution {
public:
    bool check(string s, int start,int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void helper(vector<vector<string>>& ans, vector<string>& curr,string& s,int start){
        if(start==s.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=s.size()-1;i>=start;i--){
            if(check(s,start,i)){
                curr.push_back(s.substr(start,i-start+1));
                helper(ans,curr,s,i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<string>> ans;
        vector<string> curr;
        helper(ans,curr,s,0);
        return ans;
    }
};
