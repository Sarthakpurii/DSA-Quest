class Solution {
public:
    bool isPalindrome(int x) {
        if (x>=0){
            int copy=x;
            long n=0;
            while(x!=0){
                n=(n*10)+(x%10);
                x/=10;
            }
        if (copy==n) return true;
        }
        return false;
    }
};