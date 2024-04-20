class Solution {
public:
    string largestOddNumber(string num) {
        for(int i=num.size()-1;i>-1;i--){
            if((num[i]-'0')%2==1){ 
                num.resize(i+1);
                return num;}
        }
        return "";
    }
};