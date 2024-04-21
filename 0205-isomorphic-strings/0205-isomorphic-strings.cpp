class Solution {
private:
    bool containsValue(const std::unordered_map<char, char>& map, char value) {
        for (const auto& pair : map) {
            if (pair.second == value) {
                return true;
            }
        }
        return false;
    }
public:
    bool isIsomorphic(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> m;

        for(int i=0;i<t.size();i++){
            if(m.find(t[i])==m.end()){
                if(containsValue(m,s[i])) return false;
                else m[t[i]]=s[i];
            }else{
                if(m[t[i]]!=s[i]) return false;
            }
        }


        return true;
    }
};