class Solution {
public:
    bool check(vector<int>& nums) {
        int n=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]>nums[(i+1)%nums.size()]) n++;
        }
        cout<<n;
        return n<2;
    }
};