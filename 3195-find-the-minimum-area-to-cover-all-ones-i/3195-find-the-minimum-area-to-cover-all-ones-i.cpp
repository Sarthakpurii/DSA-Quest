class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int minr=INT_MAX,minc=INT_MAX,maxr=INT_MIN,maxc=INT_MIN;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    minr=min(minr,i);
                    minc=min(minc,j);
                    maxr=max(maxr,i);
                    maxc=max(maxc,j);
                }
            }
        }
        return (maxr-minr+1)*(maxc-minc+1);
    }
};