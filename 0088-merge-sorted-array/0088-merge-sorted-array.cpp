class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(n>0)
        {for(int i=m+n-1;i>-1;i--){
            if(m==0){
            for(int i=n-1;i>-1;i--){
                nums1[i]=nums2[i];
            }
        }
            else if(nums1[m-1]>nums2[n-1]){
                nums1[i]=nums1[m-1];
                m--;
            }
            else{
                nums1[i]=nums2[n-1];
                n--;
            }
            if(n==0) break;
        }}
    }
};