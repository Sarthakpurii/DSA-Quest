class Solution {
public:
    string convert(string s, int rows) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(rows==1) return s;
        int n=s.size();
        string ans;
        ans.reserve(n);
        int patsize=2*(rows-1);
        for(int i=0;i<rows;i++){
            for(int j=0;j+i<n;j+=patsize){
                int idx=i+j;
                // cout<<idx<<" ";
                if(i==0 || i==rows-1){
                    ans.push_back(s[idx]);
                    continue;
                }
                ans.push_back(s[idx]);
                idx=idx+2*(rows-i-1);
                // cout<<idx<<" ";
                if(idx>=n) break;
                ans.push_back(s[idx]);
            }
            // cout<<endl;
        }
        return ans;
    }
};