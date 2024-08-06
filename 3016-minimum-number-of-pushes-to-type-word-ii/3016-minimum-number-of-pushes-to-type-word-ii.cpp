class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0,curr=0,i=0;
        vector<int> mp(26,0);
        for(char c:word) mp[c-'a']++;
        sort(mp.begin(),mp.end(),greater<int>());
        while(i<26){
            curr++;
            for(int j=0;j<8 && i<26;j++,i++) ans+=curr*mp[i];
        }
        return ans;
    }
};