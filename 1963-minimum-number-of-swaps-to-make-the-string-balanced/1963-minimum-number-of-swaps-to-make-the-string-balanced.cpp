class Solution {
public:
    int minSwaps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int currbalance=0,inbalance=0;
        for(char c:s){
            if(c=='[') currbalance--;
            else currbalance++;
            inbalance=max(inbalance,currbalance);
        }
        return (inbalance+1)/2;
    }
};
