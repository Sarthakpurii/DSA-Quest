class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int countt=0;
        char temp='$';
        for(char c:s){
            if(c==temp){
                if(countt<1){
                    countt++;
                    ans.push_back(c);
                }
            }
            else{
                ans.push_back(c);
                temp=c;
                countt=0;
            }
        }
        return ans;
    }
};