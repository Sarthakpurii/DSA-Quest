class Solution {
public:
    //first backtracking question, revise it again whenever encounter it
    void helper(vector<string>& sol,string curr,int closed, int open,int n){
        if(curr.size()==2*n){
            sol.push_back(curr);
            return;
        }

        if(open<n) helper(sol,curr+'(',closed,open+1,n);
        if(closed<open) helper(sol,curr+')',closed+1,open,n);
    }
    vector<string> generateParenthesis(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<string> sol;
        helper(sol,"",0,0,n);
        return sol;
    }
};