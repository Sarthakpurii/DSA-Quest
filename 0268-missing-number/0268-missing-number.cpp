class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //Aproach 1
        // sort(nums.begin(),nums.end());
        // int i=0;
        // for(i;i<nums.size();i++){
        //     if (i!=nums[i]) return i;
        //     i++;
        // }
        // return i;

        //Approach 2

        int ExpectedSum=nums.size()*(nums.size()+1)/2;
        int sum=0;
        for (int i:nums) sum+=i;
        return ExpectedSum-sum;
    }
};