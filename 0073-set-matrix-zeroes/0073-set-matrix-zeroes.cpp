class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<unordered_set<int>> position={unordered_set<int>(),unordered_set<int>()};

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    position[0].insert(i);
                    position[1].insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(position[0].find(i)!=position[0].end()) matrix[i][j]=0;
                if(position[1].find(j)!=position[1].end()) matrix[i][j]=0;
            }
        }
    }
};