class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> counter(3,0);
        for(int i=0;i<nums.size();i++){
            counter[nums[i]]++;
        }
        int index=0;
        for(int i=0;i<3;i++){
            while(counter[i]-- > 0) nums[index++]=i;
        }
    }
};