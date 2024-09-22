class Solution {
public:
    int count(long pre,int n){
        long next=pre+1;
        int c=0;
        while(pre<=n){
            c+=(int)(min(n+1L,next)-pre);
            pre*=10;
            next*=10;
        }
        return c;
    }
    int findKthNumber(int n, int k) {
        int pre=1;
        k--;
        while(k>0){
            int c=count(pre,n);
            if(c<=k){
                pre++;
                k-=c;
            }
            else{
                pre*=10;
                k--;
            }
        }
        return pre;
    }
};