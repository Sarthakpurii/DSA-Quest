class Solution {
public:
    void helper(vector<vector<string>>& ans,vector<string>& state,int col,int n,vector<bool>& updiag, vector<bool>& downdiag, vector<bool>& rowstate){
        if(col==n){
            ans.push_back(state);
            return;
        }
        for(int row=0;row<n;row++){
            if(!rowstate[row] && !updiag[row+col] && !downdiag[n-1+row-col]){
                state[row][col]='Q';
                rowstate[row]=true;
                updiag[row+col]=true;
                downdiag[n-1+row-col]=true;
                helper(ans,state,col+1,n,updiag,downdiag,rowstate);
                rowstate[row]=false;
                updiag[row+col]=false;
                downdiag[n-1+row-col]=false;
                state[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> state(n,string(n,'.'));
        vector<bool> updiag(2*n-1,false),downdiag(2*n-1,false),rowstate(n,false);
        helper(ans,state,0,n,updiag,downdiag,rowstate);
        return ans;
    }
};
// class Solution {
// public:
//     bool safe(const vector<string>& state,int row,int col,int n){
//         int r=row,c=col;
//         while(c>-1 && r>-1){
//             if(state[r--][c--]=='Q') return false;
//         }
//         r=row,c=col;
//         while(c>-1){
//             if(state[r][c--]=='Q') return false;
//         }
//         c=col;
//         while(c>-1 && r<n){
//             if(state[r++][c--]=='Q') return false;
//         }
//         return true;
//     }
//     void helper(vector<vector<string>>& ans,vector<string>& state,int col,int n){
//         if(col==n){
//             ans.push_back(state);
//             return;
//         }
//         for(int row=0;row<n;row++){
//             if(safe(state,row,col,n)){
//                 state[row][col]='Q';
//                 helper(ans,state,col+1,n);
//                 state[row][col]='.';
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> state(n,string(n,'.'));
//         helper(ans,state,0,n);
//         return ans;
//     }
// };
