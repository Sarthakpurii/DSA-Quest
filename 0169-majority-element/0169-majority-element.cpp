class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        //either sort and pick the middle in this case --> nlogn
        //create a hash table and traverse for the highest second --> O(n)

        //Implementing Moore Voting Algorithm (works when occurence>n/2) -->O(n)
        
        int  count=0,candidate;
        for(int n:nums){
            if(count==0) candidate=n;

            if(n==candidate) count++;
            else count--;
        }
        return candidate;
    }
};