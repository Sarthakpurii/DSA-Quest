class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<int,string> mp;
        int n=names.size(),j=0;
        for(int i=0;i<n;i++){
            mp[heights[i]]=names[i];
        }
        for(auto it=mp.rbegin();it!=mp.rend();it++){
            names[j++]=it->second;
        }
        return names;
    }
};