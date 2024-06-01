class Solution {
public:
    int numSteps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s.size(),num=0,ops=0,p=0;
        for(int i=n-1;i>-1;i--){
            if(s[i]=='1'){
                num+=pow(2,p);
            }
            p++;
        }
        while(num>1){
            if(num%2==1){
                num++;
                ops++;
            }
            else{
                num/=2;
                ops++;
            }
        }
        return ops;
    }
};