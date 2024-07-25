class Solution {
public:
    void pushDown(vector<int>& nums,int i,const int& n){
        int maxidx=i,l=(i*2)+1,r=(i*2)+2;
        if(l<n && nums[l]>nums[maxidx]) maxidx=l;
        if(r<n && nums[r]>nums[maxidx]) maxidx=r;
        if(maxidx!=i){
            swap(nums[i],nums[maxidx]);
            pushDown(nums,maxidx,n);
        }
    }
    void heapify(vector<int>& nums){
        int n=nums.size();
        for(int i=(n-1)/2;i>-1;i--){
            pushDown(nums,i,n);
        }
    }
    void heapSort(vector<int>& nums){
        int n=nums.size(),temp=n-1;
        for(int i=0;i<n;i++){
            swap(nums[0],nums[temp]);
            pushDown(nums,0,temp);
            temp--;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        heapify(nums);
        heapSort(nums);
        return nums;
    }
};