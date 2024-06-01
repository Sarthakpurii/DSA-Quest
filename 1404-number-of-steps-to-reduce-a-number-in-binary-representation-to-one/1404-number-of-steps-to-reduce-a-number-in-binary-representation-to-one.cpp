class Solution {
public:
    int numSteps(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n=s.size()-1,ops=0;
        while(s!="1"){
            cout<<s<<endl<<n<<endl;
            if(s[n]=='0'){
                ops++;
                s=s.substr(0,n);
                n--;
            }
            else{
                ops++;
                bool zeroEncounter=false;
                for(int i=n;i>-1;i--){
                    if(s[i]=='0'){
                        s[i]='1';
                        zeroEncounter=true;
                        break;
                    }
                    else s[i]='0';
                }
                if(!zeroEncounter){
                    s='1'+s;
                    n++;
                }
            }
        }
        return ops;
    }
};