class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=arr.size(),xxor=0;
        vector<int> preXor,ans;
        for(int i=0;i<n;i++){
            xxor^=arr[i];
            preXor.push_back(xxor);
        }
        for(const auto& q:queries){
            if(q[0]==0) ans.push_back(preXor[q[1]]);
            else ans.push_back(preXor[q[1]]^preXor[q[0]-1]);
        }
        return ans;
    }
};