class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // vector<unordered_set<int>> position={unordered_set<int>(),unordered_set<int>()};

        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if (matrix[i][j]==0){
        //             position[0].insert(i);
        //             position[1].insert(j);
        //         }
        //     }
        // }
        // for(int i=0;i<matrix.size();i++){
        //     for(int j=0;j<matrix[0].size();j++){
        //         if(position[0].find(i)!=position[0].end()) matrix[i][j]=0;
        //         if(position[1].find(j)!=position[1].end()) matrix[i][j]=0;
        //     }
        // }

        int n=mat.size(),m=mat[0].size();
        bool flag1=false,flag2=false;

        for(int i=0;i<n;i++){
            if(mat[i][0]==0){
                flag1=true;
                break;
            }
        }

        for(int j=0;j<m;j++){
            if(mat[0][j]==0){
                flag2=true;
                break;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0;
                }
            }
        }
        
        if(flag1==true){
            for(int i=0;i<n;i++) mat[i][0]=0;
        }

        if(flag2==true){
            for(int i=0;i<m;i++) mat[0][i]=0;
        }
        cout<<flag2;
    }
};