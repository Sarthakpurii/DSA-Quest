class Solution {
public:
    int passThePillow(int n, int time) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int rem=time%(2*(n-1));
        if(rem<n) return rem+1;
        return 2*(n-1)-rem+1;
    }
};