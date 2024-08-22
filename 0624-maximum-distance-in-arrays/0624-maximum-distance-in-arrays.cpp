class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        pair<int,int> mini1={INT_MAX,-1},maxi1={INT_MIN,-1};
        int mini2=INT_MAX,maxi2=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(mini1.first>nums[i][0]){
                mini2=mini1.first;
                mini1.first=nums[i][0];
                mini1.second=i;
            }
            else if(mini1.first==nums[i][0] || mini2>nums[i][0]){
                mini2=nums[i][0];
            }
            
            if(maxi1.first<nums[i].back()){
                maxi2=maxi1.first;
                maxi1.first=nums[i].back();
                maxi1.second=i;
            }   
            else if(maxi1.first==nums[i].back() || maxi2<nums[i].back()){
                maxi2=nums[i].back();
            }         
        }
        // cout<<maxi1.first<<" "<<maxi2<<" "<<mini1.first<<" "<<mini2;
        if(maxi1.second!=mini1.second) return abs(maxi1.first-mini1.first);
        return max(abs(maxi2-mini1.first),abs(maxi1.first-mini2));
    }
};