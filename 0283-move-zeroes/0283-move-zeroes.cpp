class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //Approach 1

        // int j=0;
        // for(int i=0;i<nums.size();i++){
        //     if (nums[j]==0){
        //         nums.erase(nums.begin()+j);
        //         nums.push_back(0);
        //         j--;
        //     }
        //     j++;
        // }

        // Approach 2

        int zero=0,nonzero=0;
        while(nonzero<nums.size()){
            if(nums[nonzero]!=0){
                swap(nums[zero],nums[nonzero]);
                zero++;
            }
            nonzero++;
        }
    }
};