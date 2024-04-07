class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        
        int low=1,high=arr.size()-2;
        if(high==-1) return arr[0];
        else if(arr[0]>arr[1]) return 0;
        else if(arr[high+1]>arr[high]) return high+1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid-1]) low=mid+1;
            else high=mid-1;
        }

        return -1;
    }
};