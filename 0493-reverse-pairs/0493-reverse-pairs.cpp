class Solution {
public:
    int merge(vector<int> &arr,int low,int mid,int high){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int countt=0;
        int left=low,right=mid+1;
        vector<int> temp;
        int left2=low,right2=mid+1;

        while(left2<=mid && right2<=high){
            if(arr[left2]>arr[right2]*2LL){
                countt+=mid-left2+1;
                right2++;
            }
            else left2++;
        }




        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                
                temp.push_back(arr[right++]);
            }
        }

        while(left<=mid){
            temp.push_back(arr[left++]);
        }

        while(right<=high){
            temp.push_back(arr[right++]);
        }

        for(int i=0;i<temp.size();i++){
            arr[i+low]=temp[i];
        }
        return countt;
    }
    
    int ms(vector<int> &nums,int low,int high){
        int countt=0;
        if (low==high) return countt;
        int mid=low+(high-low)/2;
        countt+=ms(nums,low,mid);
        countt+=ms(nums,mid+1,high);
        countt+=merge(nums,low,mid,high);
        return countt;
    }
    int reversePairs(vector<int>& nums) {
        return ms(nums,0,nums.size()-1);
    }
};