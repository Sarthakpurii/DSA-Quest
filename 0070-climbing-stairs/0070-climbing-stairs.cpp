class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int p1=1,p2=1;
        for(int i=2;i<=n;i++){
            int curr=p1+p2;
            p2=p1;
            p1=curr;
        }
        return p1;
    }
};