class Solution {
public:
    bool valid(vector<vector<int>>& grid,int x,int y){
        if(grid[x][y]!=5 || grid[x-1][y-1]%2!=0 || grid[x+1][y-1]%2!=0 || grid[x-1][y+1]%2!=0 || grid[x+1][y+1]%2!=0) return false;
        if((grid[x-1][y-1]+grid[x][y]+grid[x+1][y+1])!=15 || (grid[x-1][y+1]+grid[x][y]+grid[x+1][y-1]!=15)) return false;
        // vector<pair<int,int> delta1={{1,1},{-1,-1},{1,-1},{-1,1}};
        // for(int i=0;i<4;i++) grid
        vector<int> col(3,0),row(3,0);
        for(int i=x-1;i<x+2;i++){
            for(int j=y-1;j<y+2;j++){
                if (grid[i][j]==0 || grid[i][j]>9) return false;
                col[j-y+1]+=grid[i][j];
                // cout<<i<<" "<<j<<endl;
                row[i-x+1]+=grid[i][j];
            }
        }
        for(auto i: col) if(i!=15) return false;
        for(auto i: row) if(i!=15) return false;
        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        int ans=0,n=grid.size(),m=grid[0].size();
        if(n<3 || m<3) return 0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                // cout<<i<<" "<<j<<endl;
                ans+=valid(grid,i,j);
            }
        }
        return ans;
    }
};


// would have been better if the magic sq to consider was larger than 3x3
// class Solution {
// public:
//     int numMagicSquaresInside(vector<vector<int>>& grid) {
//         int n=grid.size(),m=grid[0].size();
//         if(n<3 || m<3) return 0;
//         int ans=0;
//         vector<int> ldiag(m-2,0),rdaig(m-2,0),col(m,0),row(3,0);
//         unordered_set<pair<int,int>> invalid;

//         int j=0
//         for(;j<2;j++){
//             if(grid[0][j]>9 || !grid[0][j]){
//                 for(int k=0;k<2;k++){
//                     for(int l=j-1;k<j+2;j++) invalid.insert({k,l});
//                 }
//             }
//             for(int k=0;k<3;k++) ldiag[j]+=grid[k][j+k];
//             if(ldiag[j]!=15) invalid.insert({1,j+1});
//             col[j]+=grid[0][j];
//         }
//         for(;j<m-2;j++){
//             if(grid[0][j]>9 || !grid[0][j]){
//                 for(int k=0;k<2;k++){
//                     for(int l=j-1;k<j+2;j++) invalid.insert({k,l});
//                 }
//             }
//             for(int k=0;k<3;k++) ldiag[j]+=grid[k][j+k];
//             if(ldiag[j]!=15) invalid.insert({1,j+1});
//             col[j]+=grid[0][j];
//             for(int k=0;k<3;k++) rdiag[j]+=grid[k][j-k];
//             if(rdiag[j]!=15) invalid.insert({1,j-1});
//         }
//         for(;j<m;j++){
//             if(grid[0][j]>9 || !grid[0][j]){
//                 for(int k=0;k<2;k++){
//                     for(int l=j-1;k<j+2;j++) invalid.insert({k,l});
//                 }
//             }
//             for(int k=0;k<3;k++) rdiag[j]+=grid[k][j-k];
//             col[j]+=grid[0][j];
//             if(rdiag[j]!=15) invalid.insert({1,j-1});
//         }

//         for(j=0;j<m;j++) col[j]+=grid[1][j];
//         for(j=0;j<m;j++){
//             col[j]+=grid[2][j];
//             if(col[j]!=15) invalid.insert({1,j});
//         }

//         for(int i=1;i<n-1;i++){
//             for(j=1;j<m-1;j++){
//                 if(invalid.find({i,j}))
//             }
//         }

//     }
// };