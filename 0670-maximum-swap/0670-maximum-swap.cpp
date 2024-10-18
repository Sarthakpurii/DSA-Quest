class Solution {
public:
    int maximumSwap(int num) {
        string n=to_string(num);
        int nn=n.size();
        for(int i=0;i<nn;i++){
            bool b=false;
            int sidx=i;
            for(int j=nn;j>i;j--){
                if(n[i]<n[j] && n[sidx]<n[j]){
                    b=true;
                    sidx=j;
                }
            }
            if(b){
                swap(n[sidx],n[i]);
                break;
            } 
        }
        int ans=stoi(n);
        return ans;
    }
};