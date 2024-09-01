class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans(m,vector<int>(n));
        if(m*n!=original.size()) return vector<vector<int>>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[i*n+j];
            }
        }
        return ans;
    }
};