class Solution {
public:
    string removeKdigits(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=s.size(),i=0;
        if(n==k) return "0";
        stack<char> st;
        for(;i<n;i++){
            while(!st.empty() && st.top()>s[i] && k){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        string ans;
        int stackSize=st.size(),zeroEnd=-1;
        for(int i=0;i<stackSize;i++){
            if(zeroEnd==-1 && st.top()=='0') zeroEnd=i;
            else if(st.top()!='0') zeroEnd=-1;
            ans+=st.top();
            st.pop();
        }
        ans=ans.substr(0,zeroEnd);
        reverse(ans.begin(),ans.end());
        if (ans=="") return "0";
        return ans;
    }
};