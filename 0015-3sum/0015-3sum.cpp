class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        // set<vector<int>> ans;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             if(nums[i]+nums[j]+nums[k]==0){
        //                 vector<int> temp={nums[i],nums[j],nums[k]};
        //                 sort(temp.begin(),temp.end());
        //                 ans.insert(temp);
        //             } 
        //         }
        //     }
        // }
        // return vector<vector<int>>(ans.begin(),ans.end());

        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[k]==nums[k-1]) k--;
                    while(j<k && nums[j]==nums[j+1]) j++;
                    k--;
                    j++;
                }
            }
        }
        return ans;
    }
};