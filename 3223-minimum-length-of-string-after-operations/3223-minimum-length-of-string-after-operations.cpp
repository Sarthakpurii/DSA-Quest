class Solution {
public:
    int minimumLength(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char,int> mpp;
        int n=s.size();

        for(int i=0;i<s.size();i++){
            if(mpp.find(s[i])!=mpp.end() && mpp[s[i]]>1){
                mpp[s[i]]=1;
                n-=2;
            }
            else mpp[s[i]]++;
        }
        return n;
    }
};