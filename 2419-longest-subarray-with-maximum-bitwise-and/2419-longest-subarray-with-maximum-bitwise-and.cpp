class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size()-1,maxi=0,currcount=0,maxcount=0;
        for(int i:nums){
            if(maxi<i){
                maxi=i;
                maxcount=1;
                currcount=1;
            }
            else if(maxi==i){
                currcount++;
            }
            else{
                maxcount=max(maxcount,currcount);
                currcount=0;
            }
        }
        maxcount=max(maxcount,currcount);

        return maxcount;

    }
};