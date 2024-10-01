class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mp(k,0);
        for(int i:arr) mp[((i%k)+k)%k]++;
        if(mp[0]&1) return false;
        int l=1, r=k-1;
        while(l<r){
            if(mp[l++]!=mp[r--]) return false;
        }
        return true;
    }
};