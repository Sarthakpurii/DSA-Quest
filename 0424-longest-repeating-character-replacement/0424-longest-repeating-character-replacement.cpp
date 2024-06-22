class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char,int> mapp;
        int l=0,r=0,ans=0,n=s.size(),maxf=0;
        while(r<n){
            if(++mapp[s[r]]>maxf) maxf=mapp[s[r]];
            if((r-l+1)-maxf>k)--mapp[s[l++]];
            if((r-l+1)-maxf<=k) ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};