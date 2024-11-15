// OJ: https://leetcode.com/contest/biweekly-contest-34/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(1)
// NOTE: this solution is INCORRECT. It can't pass [1,2,3,10,0,7,8,9]. I left this here just for people who landed on the same wrong idea.
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& A) {
        int N = A.size(), ans = N - 1, i;
        for (i = 1; i < N; ++i) {
            if (A[i] >= A[i - 1]) continue;
            int j = N - 1;
            while (j > i && A[j] >= A[i - 1] && (j == N - 1 || A[j] <= A[j + 1])) --j;
            ans = min(ans, j - i + 1);
            break;
        }
        if (i == N) return 0;
        for (i = N - 2; i >= 0; --i) {
            if (A[i] <= A[i + 1]) continue;
            int j = 0;
            while (j < i && A[j] <= A[i + 1] && (j == 0 || A[j] >= A[j - 1])) ++j;
            ans = min(ans, i - j + 1);
            break;
        }
        return ans;
    }
};