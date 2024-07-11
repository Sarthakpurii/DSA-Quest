class Solution {
public:
    string reverseParentheses(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<string> st;
        string temp="";
        for(char c:s){
            if(c=='('){
                st.push(temp);
                st.push(string(1,c));
                temp="";
            }
            else if(c==')'){
                reverse(temp.begin(),temp.end());
                while(st.top()!="("){
                    reverse(st.top().begin(),st.top().end());
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(temp);
                temp="";
            }
            else temp+=c;
        }
        reverse(temp.begin(),temp.end());
        while(!st.empty()){
            reverse(st.top().begin(),st.top().end());
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());

        // doing temp=st.top()+temp will result in n^2*L
        //  where n=numberofelements and L is avg len of each word
        // whereas temp+=st.top() will be nL
        // so its better to do it this way
        return temp;
    }
};