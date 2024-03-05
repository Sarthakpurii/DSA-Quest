class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        
        unordered_map<int,int> hTable;
        int solution=0,sum=0;
        hTable[sum]++;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum-k;
            if(hTable.find(rem)!=hTable.end()) solution+=hTable[rem];
            hTable[sum]++;
        }
        return solution;
    }
};