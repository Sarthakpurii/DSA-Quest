class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b){
            if(a[1]!=b[1]) return a[1]<b[1];
            return a[0]<b[0];
        });

        int last=pairs[0][1],ans=1,n=pairs.size();
        for(int i=0;i<n;i++){
            if(pairs[i][0]>last){
                last=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};