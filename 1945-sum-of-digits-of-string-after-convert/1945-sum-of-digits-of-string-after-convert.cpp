class Solution {
public:
    int getLucky(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0;
        for(char i:s){
            int temp=i-'a'+1;
            while(temp){
                ans+=temp%10;
                temp/=10;
            }
        }
        // k--;
        while(ans>9 && --k){
            int temp=0;
            while(ans){
                temp+=ans%10;
                ans/=10;
            }
            ans=temp;
        }
        return ans;

    }
};