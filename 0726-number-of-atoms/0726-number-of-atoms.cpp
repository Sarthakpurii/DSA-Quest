class Solution {
public:
    string countOfAtoms(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        stack<unordered_map<string,int>> st;
        int i=0,n=s.size();
        string ele="",quan="";
        
        unordered_map<string,int> mpp;
        while(i<n){
            if(isupper(s[i])){
                if(ele=="") ele+=s[i];
                else if(quan!=""){
                    mpp[ele]+=stoi(quan);
                    ele=s[i];
                    quan="";
                }
                else{
                    mpp[ele]++;
                    ele=s[i];
                }
            }
            else if(islower(s[i])) ele+=s[i];
            else if(isdigit(s[i])) quan+=s[i];
            else if(s[i]=='('){
                if(ele!=""){
                    if(quan!=""){
                        mpp[ele]+=stoi(quan);
                        quan="";
                    }
                    else mpp[ele]++;
                    ele="";
                }
                if(!mpp.empty()){
                    st.push(mpp);
                    mpp.clear();
                }
                st.push({{"(", 1}});
            }
            else if(s[i]==')'){
                if (ele != "") {
                    if (quan != "") {
                        mpp[ele] += stoi(quan);
                        quan = "";
                    } else {
                        mpp[ele]++;
                    }
                    ele = "";
                }
                while(i+1<n && isdigit(s[i+1])){
                    quan+=s[++i];
                }
                
                while(st.top().find("(")==st.top().end()){
                    for(auto& p:st.top()) mpp[p.first]+=p.second;
                    st.pop();
                }
                st.pop();
                if(quan!=""){
                    int multi=stoi(quan);
                    quan="";
                    for(auto& p:mpp) p.second*=multi;
                }
                st.push(mpp);
                mpp.clear();
            }
            i++;
        }

        if(ele!=""){
            if(quan!="") mpp[ele]+=stoi(quan);
            else mpp[ele]++;
        }
        if(mpp.empty()){
            mpp=st.top();
            st.pop();
        }
        while(!st.empty()){
            for(auto& p:st.top()) mpp[p.first]+=p.second;
            st.pop();
        }
        map<string,int> ompp(mpp.begin(),mpp.end());
        string ans;
        for(const auto& p:ompp){
            if(p.second!=1) ans+=p.first+to_string(p.second);
            else ans+=p.first;
        }
        return ans;
    }
};