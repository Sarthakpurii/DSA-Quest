class Solution {
public:
    int romanToInt(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sol=0,n=s.size();
        unordered_map<char,int> conv={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        for(int i=0;i<n;i++){
            // if(s[i]=='I'){
            //     if((i+1!=n) && (s[i+1]=='V' || s[i+1]=='X')) sol-=conv[s[i]];
            //     else sol+=conv[s[i]];
            // }
            // else if(s[i]=='X'){
            //     if((i+1!=n) && (s[i+1]=='L' || s[i+1]=='C')) sol-=conv[s[i]];
            //     else sol+=conv[s[i]];
            // }
            // else if(s[i]=='C'){
            //     if((i+1!=n) && (s[i+1]=='D' || s[i+1]=='M')) sol-=conv[s[i]];
            //     else sol+=conv[s[i]];
            // }
            // else sol+=conv[s[i]];

            if(i+1==n || conv[s[i]]>=conv[s[i+1]]) sol+=conv[s[i]];
            else sol-=conv[s[i]];
        }
        return sol;
    }
};