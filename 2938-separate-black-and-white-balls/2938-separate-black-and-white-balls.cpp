class Solution {
public:
    long long minimumSteps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long ans=0;
        int n=s.size()-1,r=n;
        for(int i=n;i>-1;i--){
            if(s[i]=='1'){
            ans+=(r-i);
            r--;
            }
        }
        return ans;
    }
};