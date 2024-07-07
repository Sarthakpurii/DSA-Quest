class Solution {
public:
    int numWaterBottles(int bottle, int exch) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int rem,ans=bottle;
        while(bottle/exch>0){
            rem=bottle%exch;
            bottle/=exch;
            ans+=bottle;
            bottle+=rem;
        }
        return ans;
    }
};