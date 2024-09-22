class Solution {
public:
    long long validSubstringCount(string w1, string w2) {
         long long ans=0;
        int m=w2.size(),n=w1.size(),l=0,r=0;
        vector<int> mp(26,0);
        for(char c:w2) mp[c-'a']++;
        while(r<n && l<=r){
            // cout<<r<<endl;
            if(mp[w1[r]-'a']>0) m--;
            mp[w1[r]-'a']--;
            r++;
            while(m==0) {
                // cout<<n<<" "<<r<<" "<<l<<endl;
                ans+=(n-r+1);
                mp[w1[l]-'a']++;
                if(mp[w1[l]-'a']>0) m++;
                l++;
            }
        }
        return ans;
    }
};