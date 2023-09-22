class Solution {
public:
    vector<vector<int>> MatrixMul(vector<vector<int>> a,vector<vector<int>> b){
        vector<vector<int>> ans={{0,0},{0,0}};
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ans[i][j]+=a[i][k]*b[k][j];
                }
            }
        }
        return ans;
    }

    vector<vector<int>> ExpoMul(int n){
        vector<vector<int>> ans ={{1,0},{0,1}},x = {{1,1},{1,0}};
        while(n){
            if (n&1) ans=MatrixMul(ans,x);
            x=MatrixMul(x,x);
            n/=2;
        }
        return ans;
    }
    int fib(int n) {
        vector<vector<int>> ans=ExpoMul(n);
        return ans[1][0];
    }
};
