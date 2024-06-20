class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s.size();
        int i=0,j=0,ans=0;
        while(i<n){
            unordered_set<char> sett;
            while(j<n && sett.find(s[j])==sett.end()){
                sett.insert(s[j++]);
            }
            ans=max(ans,j-i);
            i=j;
        }
        return ans;
    }
};