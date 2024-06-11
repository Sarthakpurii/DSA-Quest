class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        //O(n^2) --> TLE
        // int n=height.size();
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     int lMax=*max_element(height.begin(),height.begin()+i+1);
        //     int rMax=*max_element(height.begin()+i,height.begin()+n);
        //     ans+=min(lMax,rMax)-height[i];
        // }
        // return ans;
        
        //O(n)
        vector<int> preMax, suffMax;
        int n=height.size();
        int pre=0,suff=0;

        for(int i=0;i<n;i++){
            if(height[i]>pre) pre=height[i];
            preMax.push_back(pre);
        }
        for(int i=n-1;i>-1;i--){
            if(height[i]>suff) suff=height[i];
            suffMax.insert(suffMax.begin(),suff);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(preMax[i],suffMax[i])-height[i];
        }
        return ans;
    }

};