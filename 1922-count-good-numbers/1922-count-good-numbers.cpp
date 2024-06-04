class Solution {
public:
    int m=1e9+7;
    long long powCalc(long long x,long long y){
        if (y==1) return x;
        if(y==0) return 1;
        long long res;
        x=x%m;
        if(y&1) res=x*powCalc(x*x,y/2);
        else res=powCalc(x*x,y/2);
        return res;
    }
    int countGoodNumbers(long long n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long odd=n/2;
        long long even=n-odd;
        return ((powCalc(4LL,odd)%m)*(powCalc(5LL,even)%m))%m;
    }
};