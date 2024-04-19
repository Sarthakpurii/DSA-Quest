class Solution {
public:
    string reverseWords(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        string ans;
        int i=s.size()-1,slen=0;
        for(i;i>-1;i--){
            if(s[i]==' '){
                if(slen!=0){
                    ans+=s.substr(i+1,slen)+' ';
                    slen=0;
                }
            }
            else{
                slen++;
            }
        }
        if(slen!=0){
            ans+=s.substr(i+1,slen)+' ';
        }
        ans.pop_back();
        return ans;
    }
};