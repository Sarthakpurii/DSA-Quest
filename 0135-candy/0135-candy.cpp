class Solution {
public:
    int candy(vector<int>& rating) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int peak = 1, curr = 0, ans = 1, n = rating.size(), i = 1;
        while (i < n) {
            if (i<n && rating[i] < rating[i - 1]) {
                while (i<n && rating[i] < rating[i - 1]) {
                    curr++;
                    ans += curr;
                    i++;
                }
                if (peak < curr + 1)
                    ans += curr + 1 - peak;
                peak = 1;
                curr = 0;
            }
            if (i<n && rating[i] > rating[i - 1]) {
                while (i<n && rating[i] > rating[i - 1]) {
                    curr++;
                    ans += curr;
                    i++;
                }
                if (peak < curr + 1)
                    ans += curr + 1 - peak;
                peak = curr + 1;
                curr = 0;
            }
            while (i<n && rating[i] == rating[i - 1]) {
                ans++;
                peak = 1;
                i++;
            }
        }
        return ans;
    }
};