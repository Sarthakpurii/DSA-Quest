class Solution {
public:
    string frequencySort(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }

        
        multimap<int, char> mm;
        for (auto c : m) {
            mm.insert({c.second, c.first});
        }
        string sol = "";
        for (auto it = mm.rbegin(); it != mm.rend(); it++) {
            sol += string(it->first, it->second);
        }
        return sol;
    }
};
