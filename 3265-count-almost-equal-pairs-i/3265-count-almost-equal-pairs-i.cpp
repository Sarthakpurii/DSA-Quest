class Solution {
public:
    bool check(int a,int b){
        string s1=to_string(a),s2=to_string(b);
        int n=max(s1.size(),s2.size());
        while(s1.size()!=n){
            s1="0"+s1;
        }
        while(s2.size()!=n){
            s2="0"+s2;
        }
        vector<int> m1(10,0),m2(10,0);
        int diff=0;
        for(int i=0;i<n;i++){
            m1[s1[i]-'0']++;
            m2[s2[i]-'0']++;
            if(s1[i]!=s2[i]){
                diff++;
                if(diff>2) return false;
            }
        }
        for(int i=0;i<10;i++){
            if(m1[i]!=m2[i]) return false;
        }
        return true;
    }
    int countPairs(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans+=check(nums[i],nums[j]);
            }
        }
        return ans;
    }
};