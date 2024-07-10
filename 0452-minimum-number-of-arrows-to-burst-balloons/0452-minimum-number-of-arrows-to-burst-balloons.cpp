class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(points.begin(),points.end(),[](vector<int> &v1,vector<int> &v2){
            if(v1[0]==v2[0]) return v1[1]<v2[1];
            return v1[0]<v2[0];
        });
        int i=0,n=points.size(),arrows=0;
        while(i<n){
            int end=points[i][1];
            i++;
            arrows++;
            while(i<n && end>=points[i][0]){
                end=min(end,points[i][1]);
                i++;
            }
        }
        return arrows;
    }
};