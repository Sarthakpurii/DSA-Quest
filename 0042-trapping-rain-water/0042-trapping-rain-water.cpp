class Solution {
public:
    int trap(vector<int>& height) {
        //O(n^2)
        int n=height.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int lMax=*max_element(height.begin(),height.begin()+i+1);
            int rMax=*max_element(height.begin()+i,height.begin()+n);
            ans+=min(lMax,rMax)-height[i];
        }
        return ans;
    }
};