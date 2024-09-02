class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=chalk.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            if(k<chalk[i]) return i;
            k-=chalk[i];
            sum+=chalk[i];
        }
        k%=sum;
        for(int i=0;i<n;i++){
            if(k<chalk[i]) return i;
            k-=chalk[i];
        }
        return -1;
    }
};