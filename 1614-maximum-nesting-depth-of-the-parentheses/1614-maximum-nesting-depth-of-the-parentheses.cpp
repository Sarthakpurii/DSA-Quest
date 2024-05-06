class Solution {
public:
    int maxDepth(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int temp=0,sol=0;
        for(char c:s){
            if(c=='('){
                temp++;
                sol=max(temp,sol);
            }else if(c==')') temp--;
        }
        return sol;
    }
};
