class Solution {
public:
    bool isValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<char> st;
        for(char c:s){
            if(c=='(' or c=='{' or c=='[') st.push(c);
            else if((c==')' and st.top()!='(') || (c=='}' and st.top()!='{') || (c==']' and st.top()!='[')) return false;
            else{
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};