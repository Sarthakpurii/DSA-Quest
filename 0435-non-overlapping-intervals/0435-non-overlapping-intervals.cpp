// class Solution {
// public:
//     int eraseOverlapIntervals(vector<vector<int>>& inter) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         sort(inter.begin(),inter.end(),[](vector<int> v1,vector<int> v2){
//             // if(v1[1]==v2[1]) return v1[0]<v2[0];
//             return v1[1]<v2[1];
//         });
//         int n=inter.size(),i=1,p=0,ans=0;
//         while(i<n){
//             if(inter[p][1]>inter[i][0]){
//                 ans++;
//             }
//             else{
//                 p=i;
//             }
//             i++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });
        int prev_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (prev_end > intervals[i][0]) {
                res++;
            } else {
                prev_end = intervals[i][1];
            }
        }

        return res;        
    }
};