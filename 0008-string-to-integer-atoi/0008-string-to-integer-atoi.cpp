class Solution {
public:
    int myAtoi(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int sol = 0, sign = 1, n = s.size(), i = 0, dig;
        bool found = false;

        while (i < n && s[i] == ' ') i++; // Skip leading whitespace

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '+') ? 1 : -1; // Handle sign
        }

        
        while (i < n && isdigit(s[i])) {
            dig = s[i++] - '0';
            if (sol > INT_MAX / 10 || (sol == INT_MAX / 10 && dig > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN; // Handle overflow/underflow
            }
            sol = sol * 10 + dig;
            found = true; // Indicate that a valid number is found
        }

        if (!found) return 0; // If no valid number is found, return 0

        return sol * sign;
    }
};
