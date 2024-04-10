class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=matrix.size(),m=matrix[0].size();
        int low=0,high=n-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(matrix[mid][m-1]>=target) high=mid;
            if(matrix[mid][0]<=target) low=mid;
        }
        int row=low;
        cout<<row;
        low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]>target) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};