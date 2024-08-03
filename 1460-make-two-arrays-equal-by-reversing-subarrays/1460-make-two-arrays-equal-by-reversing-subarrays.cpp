class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int,int> mp;
        for(int i:target) mp[i]++;
        for(int i:arr){
            if(--mp[i]==-1) return false;
        }
        return true;
    }
};