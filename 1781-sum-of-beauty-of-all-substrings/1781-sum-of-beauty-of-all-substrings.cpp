class Solution {
public:
    int beautySum(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sol = 0;
        for (int i = 0; i < s.size(); i++) {
            vector<int> c(26, 0);
            for (int j = i; j < s.size(); j++) {
                c[s[j] - 'a']++;
                int maxn = 0, minn = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (c[k] > 0) {
                        maxn = max(maxn, c[k]);
                        minn = min(minn, c[k]);
                    }
                }
                sol += maxn - minn;
            }
        }
        return sol;
    }
};
