class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& banned) {
        unordered_set<string> st(banned.begin(),banned.end());
        int c=0;
        for(string s: message){
            if(st.find(s)!=st.end()) c++;
            if(c>1) return true;
        }
        return false;
    }
};