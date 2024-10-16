class Solution {
public:
    
    string longestDiverseString(int a, int b, int c) {
        set<pair<int,char>,greater<>> st;
        if(a) st.insert({a,'a'});
        if(b) st.insert({b,'b'});
        if(c) st.insert({c,'c'});
        string ans;

        while(1){
            if(st.begin()==st.end()) break;
            auto [n1,c1]=*st.begin();
            st.erase(st.begin());
            if(st.begin()==st.end()){
                int coun=2;
                while(coun && n1){
                    coun--;
                    n1--;
                    ans.push_back(c1);
                }
                break;
            }
            auto [n2,c2]=*st.begin();
            st.erase(st.begin());
            int coun =2;
            int coun2=1;
            if(n1-2<n2){
                coun2=2;
            }
            while(coun && n1){
                coun--;
                n1--;
                ans.push_back(c1);
            }
            while(coun2 && n2){
                coun2--;
                n2--;
                ans.push_back(c2);
            }
            if(n1) st.insert({n1,c1});
            if(n2) st.insert({n2,c2});
        }
        return ans;
    }
};