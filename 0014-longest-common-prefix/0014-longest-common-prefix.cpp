#include <algorithm>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=strs[0].size();
        for(int i=1;i<strs.size();i++){
            n=min(n,(int)strs[i].size());
        }

    
        int i=0;
        bool stop=false;
        for(i;i<n;i++){
            for(int j=1;j<strs.size();j++){
                if(strs[j-1][i]!=strs[j][i]){
                    stop=true;
                    break;
                } 
            }
            if(stop) break;
        }
        return (i>0)?strs[0].substr(0,i): "";
    }
};

