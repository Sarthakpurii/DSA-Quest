class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> solution;
        
        int row=matrix.size(),col=matrix[0].size();
        int top=0,bottom=row-1,left=0,right=col-1;


        while(solution.size()<row*col){
            for(int i=left;i<=right;i++){
                solution.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top;i<=bottom;i++){
                solution.push_back(matrix[i][right]);
            }
            right--;

            if(top<=bottom){
            for(int i=right;i>=left;i--){
                solution.push_back(matrix[bottom][i]);
            }
            bottom--;}

            if(left<=right){
            for(int i=bottom;i>=top;i--){
                solution.push_back(matrix[i][left]);
            }
            left++;}
        }
        return solution;
    }
};