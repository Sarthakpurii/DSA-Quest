class Solution {
public:
    bool checkValidString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int openMin=0,openMax=0;
        for(char c:s){
            if(c=='('){
                openMin++;
                openMax++;
            }
            else if(c==')'){
                if(openMax<1) return false;
                else openMax--;
                if(openMin>0) openMin--;
            }
            else{
                if(openMin>0) openMin--;
                openMax++;
            }
        }
        if(!openMin) return true;
        return false;
    }
};