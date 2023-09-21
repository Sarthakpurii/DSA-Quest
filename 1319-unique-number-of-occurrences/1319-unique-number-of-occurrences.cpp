class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        for(int num : arr) map[num]++;
        vector<int> occurrence;
        for(const auto& pair:map){
            occurrence.push_back(pair.second);
        }
        set<int> s(occurrence.begin(),occurrence.end());
        if (s.size()==occurrence.size()) return true;
        else return false;
    }
};