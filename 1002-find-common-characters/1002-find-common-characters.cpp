class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> res(26,0);
        for(char c:words[0]) res[c-'a']++;
        for(int i=1;i<words.size();i++){
            vector<int> comp(26,0);
            for(char c:words[i]) comp[c-'a']++;
            for(int j=0;j<26;j++){
                res[j]=min(res[j],comp[j]);
            }
        }
        vector<string> sol;
        for(int i=0;i<26;i++){
            for(int j=0;j<res[i];j++){
                sol.push_back(string(1,(char)(97+i)));
            }
        }
        return sol;
    }
};