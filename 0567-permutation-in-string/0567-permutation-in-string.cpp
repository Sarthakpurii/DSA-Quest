class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26,0);
        for(char c: s1) mp[c-'a']++;
        int size=0,n=s1.size(),l=0,r=0;
        while(r<s2.size()){
            while(size<n && r<s2.size()){
                if(mp[s2[r]-'a']>0) size++;
                mp[s2[r++]-'a']--;
                // cout<<l<<" "<<r<<endl;
            }
            while(r-l>n){
                if(++mp[s2[l++]-'a']>0) size--;
                // cout<<l<<" "<<r<<endl;
            }
            if(size==n) return true;
        }
        return false;
    }
};