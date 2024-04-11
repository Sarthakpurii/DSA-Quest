class Solution {
public:
    string removeOuterParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string ans;
        int open=0;
        for(char i:s){
            if(i=='(' && ++open>1) ans+=i;
            else if(i==')' && --open>0) ans+=i;
        }
        return ans;
    }
};