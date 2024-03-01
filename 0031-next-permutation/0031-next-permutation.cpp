class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        
        int breakPoint=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                breakPoint=i-1;
                break;
            }
        }

        if(breakPoint>-1){
            int minSwap=INT_MAX,minSwapIndex;
            for(int i=nums.size()-1;i>breakPoint;i--){
                if(nums[i]>nums[breakPoint] && nums[i]<minSwap){
                    minSwap=nums[i];
                    minSwapIndex=i;
                }
            }
            swap(nums[breakPoint],nums[minSwapIndex]);
        }

        reverse(nums.begin()+breakPoint+1,nums.end());
    }
};