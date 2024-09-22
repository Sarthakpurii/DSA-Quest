class Solution {
public:
    long long minNumberOfSeconds(int blocks, vector<int>& t) {
        int n=t.size();
        long long ans=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
        for(int i=0;i<n;i++){
            pq.push({t[i],1});
        }
        while(blocks){
            auto [time,multi]=pq.top();
            pq.pop();
            long long sum=multi*(multi+1)/2;
            long long val=time/sum;
            multi++;
            pq.push({time+val*(multi),multi});
            ans=max(time,ans);
            blocks--;
        }
        return ans;
    }
};