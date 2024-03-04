class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n=matrix.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++) swap(matrix[i][j],matrix[i][n-j-1]);
        }
    }
};