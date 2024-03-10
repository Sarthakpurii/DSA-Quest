class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        // int n=nums.size();
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




        // sort(nums.begin(),nums.end());
        // vector<vector<int>> ans;
        // for(int i=0;i<n;i++){
        //     if(i>0 && nums[i]==nums[i-1]) continue;
        //     int j=i+1;
        //     int k=n-1;
        //     while(j<k){
        //         int sum=nums[i]+nums[j]+nums[k];
        //         if(sum>0){
        //             k--;
        //         }
        //         else if(sum<0){
        //             j++;
        //         }
        //         else{
        //             ans.push_back({nums[i],nums[j],nums[k]});
        //             while(j<k && nums[k]==nums[k-1]) k--;
        //             while(j<k && nums[j]==nums[j+1]) j++;
        //             k--;
        //             j++;
        //         }
        //     }
        // }
        // return ans;

        

        vector<vector<int>> ans;
        if(all_of(nums.begin(),nums.end(),[&](const int i){return i==0;})) return{{0,0,0}};
        int min=*min_element(nums.begin(),nums.end()),max=*max_element(nums.begin(),nums.end()),target;
        if(min>=0 || max<=0) return {};
        int range=max-min+1,exist=0;
        vector<int> count(range,0);
        for(int i:nums) count[i-min]++;
        for(int i=0;i<range;i++) if(count[i]!=0) nums[exist++]=i+min;
        
        auto l=nums.begin(),r=next(l,exist-1);
        while(*l<=0){
            while(*r>=0){
                target=-(*r+*l);
                if (target < *l) {
                        --r;
                        continue;
                    }
                if (target > *r) break;
                if(((target==*r || target==*l) && count[target-min]==1) || 
                    ((target==*r && target==*l) && count[target-min]==2)){
                    r--;
                    continue;
                }
                if(count[target-min]!=0) ans.push_back({*r,*l,target});
                r--;
            }
            l++;
            r=next(nums.begin(),exist-1);
        }

    return ans;
    }

};