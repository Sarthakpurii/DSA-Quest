class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0,j=0,sw=0,n1=nums1.size(),n2=nums2.size();
        while(i<n1 && j<n2){
            if(nums1[i]==nums2[j]){
                swap(nums1[sw++],nums1[i++]);
                j++;
            } 
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return vector<int>(nums1.begin(),nums1.begin()+sw);
    }
};