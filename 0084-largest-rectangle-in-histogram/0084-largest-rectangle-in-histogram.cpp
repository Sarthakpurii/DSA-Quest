class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=heights.size();
        stack<int> st;
        vector<int> left(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]) st.pop();
            if(!st.empty()) left[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        int ans=INT_MIN;
        for(int i=n-1;i>-1;i--){
            int right=n;
            while(!st.empty() && heights[st.top()]>heights[i]) st.pop();
            if(!st.empty()) right=st.top();
            st.push(i);
            ans=max(ans,heights[i]*(right-left[i]-1));
        }
        return ans;


    }
};
