class Solution {
public:
    string reverseWords(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i=0,left=0,right=0,n=s.size()-1;
        reverse(s.begin(),s.end());

        while(i<=n){
            while(i<=n && s[i]==' ')i++;
            if(i>n) break;            //As now the i is out of bounds
            while(i<=n && s[i]!=' '){
                s[right++]=s[i++];
            }
            reverse(s.begin()+left,s.begin()+right);
            s[right++]=' ';
            left=right;
            i++;
            
        }
        s.resize(right-1);
        return s;



        // ----Takes Extra Space--- 

        // string ans;
        // int i=s.size()-1,slen=0;
        // for(i;i>-1;i--){
        //     if(s[i]==' '){
        //         if(slen!=0){
        //             ans+=s.substr(i+1,slen)+' ';
        //             slen=0;
        //         }
        //     }
        //     else{
        //         slen++;
        //     }
        // }
        // if(slen!=0){
        //     ans+=s.substr(i+1,slen)+' ';
        // }
        // ans.pop_back();
        // return ans;
    }
};