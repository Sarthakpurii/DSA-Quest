class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum=0,n=skill.size();
        for(int i: skill) sum+=i;
        if(sum%(n/2)) return -1;
        int target=sum/(n/2);
        unordered_map<int,int> mp;
        long long chem=0;
        for(int i:skill){
            if(mp.find(target-i)!=mp.end()){
                chem+=((target-i)*i);
                mp[target-i]--;
                if(mp[target-i]==0) mp.erase(target-i);
            }
            else mp[i]+=1;
        }
        if(mp.empty()) return chem;
        return -1;
    }
};