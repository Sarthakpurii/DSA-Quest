class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return {};
        for(int i=0;i<=n-4;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<=n-3;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k=j+1,l=n-1;
                while(k<l){
                    long long sum=static_cast<long long>(nums[i])+nums[j]+nums[k]+nums[l];
                    if(sum>target){
                        while(k<l && nums[l]==nums[l-1]) l--;
                        l--;
                    }
                    else if(sum<target){
                        while(k<l && nums[k]==nums[k+1]) k++;
                        k++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        while(k<l && nums[l]==nums[l-1]) l--;
                        l--;
                        while(k<l &&nums[k]==nums[k+1]) k++;
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};