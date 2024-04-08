class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int low=INT_MIN,high=0;
        for(int i:weights){
            high+=i;
            if(i>low) low=i;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            bool isPossible=deliveryPossible(weights,days,mid);
            if(isPossible) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
private: 
    bool deliveryPossible(vector<int> nums,int days,int maxCap){
        int idx=0;
        while(days--){
            int tempCap=maxCap;
            while(idx<nums.size() && tempCap>=nums[idx]){
                tempCap-=nums[idx];
                idx++;
            }
            if(idx==nums.size()) return true;
        }
        return false;
    }
};