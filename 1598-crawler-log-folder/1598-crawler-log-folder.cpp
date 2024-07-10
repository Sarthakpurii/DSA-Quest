class Solution {
public:
    int minOperations(vector<string>& logs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0;
        for(string s:logs){
            if(s[0]=='.'){
                if(s[1]=='.' && ans>0) ans--;
            }
            else ans++;
        }
        return ans;
    }
};