class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        // long long sol=0;
        // for(int i=0;i<n-1;i++){
        //     int minn=min(nums[i],nums[i+1]);
        //     int maxx=max(nums[i],nums[i+1]);
        //     sol+=maxx-minn;
        //     for(int j=i+2;j<n;j++){
        //         minn=min(nums[j],minn);
        //         maxx=max(nums[j],maxx);
        //         sol+=maxx-minn;
        //     }
        // }
        // return sol;
        stack<int> st;
        vector<int> leftMin(n,0),leftMax(n,0),rightMin(n,0),rightMax(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
            if(st.empty()) leftMin[i]=i+1;
            else leftMin[i]=i-st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>-1;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            if(st.empty()) rightMin[i]=n-i;
            else rightMin[i]=st.top()-i;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
            if(st.empty()) leftMax[i]=i+1;
            else leftMax[i]=i-st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1;i>-1;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(st.empty()) rightMax[i]=n-i;
            else rightMax[i]=st.top()-i;
            st.push(i);
        }
        long long sol=0;
        for(int i=0;i<n;i++){
            sol+=(nums[i]*leftMax[i]*rightMax[i])-(nums[i]*leftMin[i]*rightMin[i]);
        }
    return sol;
    }
};