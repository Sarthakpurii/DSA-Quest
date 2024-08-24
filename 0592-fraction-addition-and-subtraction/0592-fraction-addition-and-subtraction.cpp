class Solution {
public:
    string fractionAddition(string exp) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int s=exp.size(),i=0,n=0,d=1;
        while(i<s){
            int sign=1;
            if(exp[i]=='+') i++;
            if(exp[i]=='-'){
                sign=-1;
                i++;
            }
            int num=0;
            while(i<s && isdigit(exp[i])){
                num=num*10+(exp[i++]-'0');
            }
            num*=sign;
            int den=0;
            i++;
            while(i<s && isdigit(exp[i])){
                den=den*10+(exp[i++]-'0');
            }
            n=n*den+num*d;
            d*=den;
            int g=gcd(abs(n),d);
            n/=g;
            d/=g;
        }
        return to_string(n)+"/"+to_string(d);
    }
};

// Try this later
// class Solution {
// public:
//     string fractionAddition(string expression) {
//         stringstream ss(expression);
//         char op;
//         int a,b,c,d;
//         int num,den;
//         ss>>a;ss>>op;ss>>b; //extracting the 1st 2 numbers
//         while(ss>>c) //til we have the number
//         {
//             ss>>op; // op is the operator. which is '/' in our case
//             ss>>d;
//             num= a*d + b*c;
//             den= b*d;
//             a= num/__gcd(abs(num),abs(den));
//             b= den/__gcd(abs(num),abs(den));
//         }
//         c=__gcd(abs(a),abs(b));
//         a=a/c;
//         b=b/c;
//         return to_string(a)+'/'+to_string(b);
//     }
// };