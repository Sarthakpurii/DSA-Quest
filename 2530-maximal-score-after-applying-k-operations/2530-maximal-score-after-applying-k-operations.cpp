class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i:nums) pq.push(i);
        
        long long ans=0;
        while(k--){
            int elem=pq.top();
            if(elem==1) break;
            pq.pop();
            // cout<<ceil(elem/3.0)<<endl;
            ans+=elem;
            pq.push((elem+2)/3);
        }
        return ans+k+1;
    }
};