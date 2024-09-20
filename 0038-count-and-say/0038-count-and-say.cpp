class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        stringstream ans;
        char curr=s[0];
        int count=0;
        for(char c:s){
            if(c==curr) count++;
            else{
                ans<<to_string(count)<<curr;
                curr=c;
                count=1;
            }
        }
        if(count) ans<<to_string(count)<<curr;
        else ans<<curr;
        return ans.str();
    }
};