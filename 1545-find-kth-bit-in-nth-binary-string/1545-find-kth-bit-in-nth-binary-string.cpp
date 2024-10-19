class Solution {
public:
    char findKthBit(int n, int k) {
        if(k==1) return '0';
        if(k==2) return '1';

        int lim=log2(k);
        int rang=pow(2,lim+1)-1;
        int c=0;
        while(1){
            // cout<<c<<" "<<rang<<" " <<k<<endl;
            if(rang==1) return (c&1)?'1':'0';
            if(rang==2) return (c&1)?'0':'1';
            int mid=rang/2+1;
            if(k==mid) return (c&1)?'0':'1';
            if(k>mid){
                // k=mid-(k-mid)
                k=2*mid-k;
                c++;
            }
            rang=mid-1;
        }
        return '9';
    }
};

// class Solution {
// public:
//     string reversee(string s){
//         for(int i=0;i<s.size();i++) s[i]=s[i]=='0'?'1':'0';
//         reverse(s.begin(),s.end());
//         return s;
//     }
//     char findKthBit(int n, int k) {
//         string s="0";
//         int lim=log2(k);
//         // cout<<b;
//         for(int i=1;i<=lim;i++){
//             string temp=s+"1"+reversee(s);
//             s=temp;
//         }
//         return s[k-1];
//     }
// };