class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=mat.size(),m=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int col=maxCol(mat,mid,m);
            int up= (mid-1>=0) ? mat[mid-1][col] : -1;
            int down= (mid+1<n) ? mat[mid+1][col] : -1;
            if(mat[mid][col]>up && mat[mid][col]>down) return {mid,col};
            else if(mat[mid][col]<up) high=mid-1;
            else low=mid+1;
        }
        return {-1,-1};
    }
private:
    int maxCol(vector<vector<int>> mat,int mid,int m){
        int maxx=-1,idx=-1;
        for(int i=0;i<m;i++){
            if(mat[mid][i]>maxx){
                maxx=mat[mid][i];
                idx=i;
            }
        }
        return idx;
    }
};