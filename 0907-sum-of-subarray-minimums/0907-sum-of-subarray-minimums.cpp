class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=arr.size();
        vector<int> left(n,0),right(n,0);
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st.empty() && st.top().first>arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            left[i]=cnt;
        }
        while(!st.empty()) st.pop();

        for(int i=n-1;i>-1;i--){
            int cnt=1;
            while(!st.empty() && st.top().first>=arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            right[i]=cnt;
        }
        long long sol=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            sol=(sol+((long long)arr[i]*left[i]%mod*right[i]%mod))%mod;
        }
        return sol;
    }
};
