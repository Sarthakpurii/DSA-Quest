class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long x=0,x1=0,x2=0;
        for(int i:nums) x^=i;
        x=(x&(x-1))^x;
        for(int i:nums){
            if(i&x) x1^=i;
            else x2^=i;
        }
        return {(int)x1,(int)x2};
    }
};