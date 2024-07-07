class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newinter) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=inter.size(),low=0,high=n-1,ans=-11;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(newinter[0]==inter[mid][0]){
                ans=mid;
                break;
            }
            else if(newinter[0]<inter[mid][0]) high=mid-1;
            else low=mid+1;
        }
        if(ans==-11) ans=high;
        if(ans==-1){
            int last=-111;
            while(!inter.empty() && inter[0][0]<newinter[1]){
                last=inter[0][1];
                inter.erase(inter.begin());
            }
            newinter[1]=max(newinter[1],last);
            inter.insert(inter.begin(),newinter);
        }
        else{
            if(inter[ans][1]>=newinter[0]){
                int last=inter[ans][1];
                while(inter.size()>=ans+2 && inter[ans+1][0]<=newinter[1]){
                    last=inter[ans+1][1];
                    inter.erase(inter.begin()+ans+1);
                }
                inter[ans][1]=max(newinter[1],last);
            }
            else{
                int last=inter[ans][1];
                while(inter.size()>=ans+2 && inter[ans+1][0]<=newinter[1]){
                    last=inter[ans+1][1];
                    inter.erase(inter.begin()+ans+1);
                }
                newinter[1]=max(newinter[1],last);
                inter.insert(inter.begin()+ans+1,newinter);
            }
        }
        cout<<ans;
        return inter;
    }
};