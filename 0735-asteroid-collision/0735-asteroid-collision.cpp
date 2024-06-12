class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            bool equalMass=false,destroyed=false;
            while(!st.empty() && signbit(st.top())!=signbit(nums[i])){

                if(abs(st.top())<abs(nums[i])){
                    st.pop();
                }
                else if(abs(st.top())==abs(nums[i])){
                    st.pop();
                    equalMass=true;
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }
            }
            if(equalMass) continue;
            if(!destroyed) st.push(nums[i]);
        }
        int stSize=st.size();
        for(int i=stSize-1;i>-1;i--){
            nums[i]=st.top();
            cout<<st.top()<<" ";
            st.pop();
        }
        nums.erase(nums.begin()+stSize,nums.end());
        return nums;
    }
};