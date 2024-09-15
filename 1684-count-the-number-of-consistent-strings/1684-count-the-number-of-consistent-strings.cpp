class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<bool> m(26,false);
        for(char c:allowed) m[c-'a']=true;
        int ans=0;
        for(const string& s:words){
            bool consistent=true;
            for(const char& c:s){
                if(!m[c-'a']){
                    consistent=false;
                    break;
                }
            }
            ans+=consistent;
        }
        return ans;
    }
};