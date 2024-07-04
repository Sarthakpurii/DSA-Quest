class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> change(2,0);
        for(int i:bills){
            if(i==5){
                change[0]++;
                continue;
            }
            else if(i==10){
                if (change[0]==0) return false;
                change[1]++;
                change[0]--;
                continue;
            }
            else{
                if((change[0]<3 && change[1]==0)|| (change[0]==0)) return false;
                if(change[1]==0) change[0]-=3;
                else{
                    change[0]--;
                    change[1]--;
                }
            }
        }
        return true;

    }
};