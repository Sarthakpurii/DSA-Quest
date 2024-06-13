class Solution {
public:
    int currentHistogramMax(vector<int> arr,int m){
        stack<int> st;
        vector<int> left(m,-1);
        
        for(int i=0;i<m;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        int ans=INT_MIN;
        for(int i=m-1;i>-1;i--){
            int right=m;
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) right=st.top();
            st.push(i);
            ans=max(ans,arr[i]*(right-left[i]-1));

        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=matrix.size(),m=matrix[0].size();
        vector<int> currentState(m,0);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') currentState[j]=0;
                else currentState[j]++;
            }
            ans=max(ans,currentHistogramMax(currentState,m));
        }
        return ans;


    }
};