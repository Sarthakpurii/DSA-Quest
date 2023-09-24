class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max=0, temp=0;
        for (int i:nums){
            if (i==1) temp++;
            else{
                if (max<temp) max=temp;
                temp=0;
            }
        }
        if (max<temp) return temp;
        return max;
    }
};