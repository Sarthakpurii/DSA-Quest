class Solution {
public:
    int numberOfSubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char,int> mapp;
        int r=0,l=0,ans=0,n=s.size();
        while(r<n){
            mapp[s[r]]++;
            while(mapp.size()>2){
                ans+=n-r;
                if(!--mapp[s[l]]) mapp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};