class Solution {
public:
    
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n=folder.size();
        vector<string> ans;
        string currpar=folder[0]+'/';
        ans.push_back(folder[0]);
        for(int i=1;i<n;i++){
            if(folder[i].find(currpar)==0) continue;
            ans.push_back(folder[i]);
            currpar=folder[i]+'/';
        }
        return ans;
    }
};