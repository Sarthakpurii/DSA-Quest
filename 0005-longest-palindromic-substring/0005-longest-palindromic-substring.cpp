class Solution {
public:
    string expandAroundCenter(string s,int l,int r){
        while(l>-1 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(s.size()<=1) return s;
        
        string maxs=s.substr(0,1);
        for(int i=0;i<s.size();i++){
            string odd=expandAroundCenter(s,i,i);
            string even=expandAroundCenter(s,i,i+1);

            if(odd.size()>maxs.size()) maxs=odd;
            if(even.size()>maxs.size()) maxs=even;
        }
        return maxs;
        
    }
};