class Solution {
public:
    int longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char,int> m;
        int sol=0;
        for(char i:s) m[i]++;
        
        for(auto it=m.begin();it!=m.end();){
            sol+=2*(it->second/2);
            if(it->second%2==0) it=m.erase(it);
            else ++it;
        }
        if(m.size()) sol++;
        return sol;
    }
};