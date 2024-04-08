class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if((long)m*k>bloomDay.size()) return -1;
        int low=1,high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            bool boq=noOfBoquets(bloomDay,mid,m,k);
            if(boq) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
private:
    bool noOfBoquets(vector<int> nums,int day,int m,int k){
        int flower=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=day){
                flower++;
                if(flower==k){
                    m--;
                    flower=0;
                    if(m==0) return true;
                }
            }
            else flower=0;
        }
        return false;
    }
};