class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> solution;
        for(int i=1;i<=numRows;i++){
            vector<int> semi(i,1);
            for(int j=1;j<i-1;j++){
                semi[j]=solution[i-2][j-1]+solution[i-2][j];
            }
            solution.push_back(semi);
        }
        return solution;
    }
};