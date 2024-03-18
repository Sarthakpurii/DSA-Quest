class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int start=binarySearch(nums,target,true);
        int end=-1;
        if(start!=-1) end=binarySearch(nums,target,false);
        return {start,end};
    }
private:
    int binarySearch(vector<int> &nums,int target,bool isStart){
        int low=0,high=nums.size()-1,idx=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                idx=mid;
                if(isStart){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return idx;
    }
};