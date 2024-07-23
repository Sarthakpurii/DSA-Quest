class Solution {
public:
    
    vector<int> frequencySort(vector<int>& nums) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int,int> mpp;
        int n=nums.size(),idx=0;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        vector<pair<int,int>> sortedvec;
        for(auto it:mpp){
            sortedvec.push_back({it.second,it.first});
        }
        sort(sortedvec.begin(),sortedvec.end(),[](const pair<int,int>& p1,const pair<int,int>& p2){
            if(p1.first!=p2.first) return p1.first<p2.first;
            return p1.second>p2.second;
        });
        for(const auto& p:sortedvec){
            for(int i=0;i<p.first;i++) nums[idx++]=p.second;
        }
        return nums;

    }
};