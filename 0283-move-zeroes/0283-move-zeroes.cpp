class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int pointer=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[pointer]=nums[i];
                pointer++;
            }
        }
        for(pointer;pointer<nums.size();pointer++){
            nums[pointer]=0;
        }
    }
};