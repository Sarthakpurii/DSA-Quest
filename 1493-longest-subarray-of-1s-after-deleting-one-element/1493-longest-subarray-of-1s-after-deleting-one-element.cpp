class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bool zero=false;
        int sol=0,prev=0,curr=0;
        for(int i:nums){
            if(i==0){
                zero=true;
                sol=max(sol,prev+curr);
                prev=curr;
                curr=0;
            }
            else{
                curr++;
            }
        }
        if(!zero) return curr-1;
        else{
            sol=max(sol,prev+curr);
        }
        return sol;

    }
};