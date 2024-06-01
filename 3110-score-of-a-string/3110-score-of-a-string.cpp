class Solution {
public:
    int scoreOfString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s.size()-1,sol=0;
        for(;n>0;n--){
            sol+=abs(s[n]-s[n-1]);
        }
        return sol;
    }
};