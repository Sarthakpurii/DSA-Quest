class Solution {
public:
    bool rotateString(string s, string goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if (s==goal) return true;
        int len=s.size();

        
        for(int i=0;i<len-1;i++){
            s=s.substr(1,len-1)+s[0];
            if (s==goal) return true;
        }
        return false;
    }
};
