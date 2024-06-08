class Solution {
public:
    // double powCalc(double x, int n){
    //     if(n==1) return x;
    //     double sol=powCalc(x,n-1)*x;
    //     return sol;
    // }
    // double myPow(double x, int n) {
    //     if (n==0) return 1;
    //     bool neg=(n<0);
    //     n=abs(n);
    //     double sol;
    //     sol=powCalc(x,n);
    //     if (neg) return 1/sol;
    //     return sol;
    // }

    double powCalc(double x,int n){
        if(n==1) return x;
        double sol;
        if(n%2==1){
            sol=x*powCalc(x,n-1);
        }
        else{
            sol=powCalc(x*x,n/2);
        }
        return sol;
        
    }
    double myPow(double x, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (n==0) return 1;
        bool neg=(n<0);
        n=abs(n);
        double sol=powCalc(x, n);
        if(neg) return 1/sol;
        return sol;
    }
};
