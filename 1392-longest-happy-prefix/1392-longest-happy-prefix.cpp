class Solution {
public:
    string longestPrefix(string s) {
        // string r=s;
        // reverse(r.begin(),r.end());
        int n=s.size();
        long hashs1=0,hashs2=0,hashr1=0,hashr2=0,multir1=1,multir2=1;
        int mod1=1e9+7,mod2=1e9+33;
        int idx=-1;
        for(int i=0;i<n-1;i++){
            hashs1=((hashs1*26)%mod1+(s[i]-'a')+mod1)%mod1;
            hashs2=((hashs2*27)%mod2+(s[i]-'a')+mod2)%mod2;
            hashr1=(hashr1+((s[n-1-i]-'a')*multir1)%mod1+mod1)%mod1;
            multir1=(multir1*26)%mod1;
            hashr2=(hashr2+((s[n-1-i]-'a')*multir2)%mod2+mod2)%mod2;
            multir2=(multir2*27)%mod2;
            if(hashs1==hashr1 && hashs2==hashr2) idx=i;
        }
        return s.substr(0,idx+1);
    }
};