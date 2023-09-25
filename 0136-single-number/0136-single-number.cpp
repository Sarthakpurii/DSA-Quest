class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sum=0;
        for (int i:nums){
            sum^=i;
        }
        return sum;
    }
};