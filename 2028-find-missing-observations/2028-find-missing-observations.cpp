class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int nm=n+rolls.size(),sum=mean*nm,i=0;
        vector<int> ans;
        for(auto i:rolls) sum-=i;
        if(sum-n+1<1 || sum/(1.0*n)>6.0 ) return ans;
        
        for(;i<n;i++){
            int temp=sum-(n-i)+1;
            if(temp<7){
                ans.push_back(temp);
                break;
            }
            sum-=6;
            ans.push_back(6);
        }
        i++;
        for(;i<n;i++) ans.push_back(1);
        return ans;
    }
};