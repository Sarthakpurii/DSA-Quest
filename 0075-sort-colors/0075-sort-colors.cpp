class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // vector<int> counter(3,0);
        // for(int i=0;i<nums.size();i++){
        //     counter[nums[i]]++;
        // }
        // int index=0;
        // for(int i=0;i<3;i++){
        //     while(counter[i]-- > 0) nums[index++]=i;
        // }

        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                mid++;
                low++;}
            else if(nums[mid]==2){
                swap(nums[high],nums[mid]);
                high--;
            }
            else mid++;
            }
    }
};