class Solution {
public:
    void rotate(vector<int>& v, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        k=k%v.size();
        if(k!=0){
            reverse(v.begin(),v.end());
            reverse(v.begin(),v.begin()+k);
            reverse(v.begin()+k,v.end());
        }
    }
};