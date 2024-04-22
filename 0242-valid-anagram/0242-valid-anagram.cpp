class Solution {
private:
    void strToMap(string s, unordered_map<char,int> &m){
        for(char c:s){
            if(m.contains(c)) m[c]++;
            else m[c]=1;
        }
    }
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (s.size()!=t.size()) return false;
        unordered_map<char,int> sMap,tMap;
        strToMap(s,sMap);
        strToMap(t,tMap);
        if(sMap.size()!=tMap.size()) return false;
        for(pair p:sMap){
            if(!tMap.contains(p.first) || tMap[p.first]!=p.second) return false;
        }
        return true;
    }
};