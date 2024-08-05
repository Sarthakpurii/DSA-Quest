class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string,int> mp;
        for(string s:arr) mp[s]++;
        for(string s:arr){
            if(mp[s]==1) k--;
            if(k==0) return s;
        }
        return "";
    }
};