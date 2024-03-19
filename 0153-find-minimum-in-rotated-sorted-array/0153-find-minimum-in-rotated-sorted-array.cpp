class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[low]<=nums[mid]){
                if (nums[mid]<=nums[high]) return nums[low];
                else low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return 0;
    }
};