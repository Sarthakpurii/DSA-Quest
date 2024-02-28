class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int check=0;
        for(int i=1;i<nums.size();i++){
            if(nums[check]!=nums[i]){
                check++;
                nums[check]=nums[i];
            }
        }
        return check+1;
    }
};