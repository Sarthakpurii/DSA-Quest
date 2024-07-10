class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<int> st;
        for(string s:tokens){
            if(isdigit(s[0]) || (s.size()>1 && s[0]=='-')) st.push(stoi(s));
            else if(s[0]=='+'){
                int num=st.top();
                st.pop();
                st.top()+=num;
            }
            else if(s[0]=='*'){
                int num=st.top();
                st.pop();
                st.top()*=num;
            }
            else if(s[0]=='-'){
                int num=st.top();
                st.pop();
                st.top()-=num;
            }
            else if(s[0]=='/'){
                int num=st.top();
                st.pop();
                st.top()/=num;
            }
        }
        return st.top();
    }
};