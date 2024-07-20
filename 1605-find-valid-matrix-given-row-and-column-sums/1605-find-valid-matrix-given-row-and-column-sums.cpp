class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& row, vector<int>& col) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=row.size(),m=col.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<m;j++){
                int ele=min(row[i],col[j]);
                row[i]-=ele;
                col[j]-=ele;
                temp.push_back(ele);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};