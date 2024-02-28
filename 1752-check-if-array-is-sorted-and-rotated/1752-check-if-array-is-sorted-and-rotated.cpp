class Solution {
public:
    bool check(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int check=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                check++;
                if (check>1) return false;
            }
        }
        return true;
    }
};