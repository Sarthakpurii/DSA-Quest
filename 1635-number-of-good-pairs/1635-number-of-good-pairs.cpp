class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>umap;
        for(auto num:nums){
            umap[num] += 1;
        }
        int total_count = 0;
        for(auto ans:umap){
            total_count += (ans.second*(ans.second-1))/2;
        }
        return total_count;
    }
};