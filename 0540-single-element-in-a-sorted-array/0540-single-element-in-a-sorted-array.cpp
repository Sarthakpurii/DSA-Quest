class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int low=1,high=arr.size()-2;
        if(arr.size()==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[high+1]!=arr[high]) return arr[high+1];

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
            else if (mid%2==0) {
                if (arr[mid]!=arr[mid+1]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(arr[mid]!=arr[mid-1]) high=mid-1;
                else low=mid+1;
            }
        }
        return 0;
    }
};