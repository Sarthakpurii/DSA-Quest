class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
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