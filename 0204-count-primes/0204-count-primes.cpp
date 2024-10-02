class Solution {
public:
    int countPrimes(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<bool> primes(n+1,true);
        for(int i=4;i<=n;i+=2){
            primes[i]=false;
        }
        for(int i=3;i*i<=n;i+=2){
            for(int j=i*i;j<=n;j+=i) primes[j]=false;
        }
        int c=0;
        for(int i=2;i<n;i++) if(primes[i]) c++;
        return c;
    }
};