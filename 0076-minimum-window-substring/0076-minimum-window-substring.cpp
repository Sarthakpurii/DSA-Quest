class Solution {
public:
    string minWindow(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int len=INT_MAX,si=-1,r=0,l=0,count=0;
        unordered_map<char,int> mapp;
        for(char c:t) mapp[c]++;
        while(r<s.size()){
            if(mapp[s[r]]>0) count++;
            mapp[s[r]]--;
            while(count==t.size()){
                if(r-l+1<len){
                    len=r-l+1;
                    si=l;
                }
                if(mapp[s[l]]>=0) count--;
                mapp[s[l++]]++;
            }
            r++;
            
        }
        cout<<len;
        if(si==-1) return "";
        return s.substr(si,len);
    }
};