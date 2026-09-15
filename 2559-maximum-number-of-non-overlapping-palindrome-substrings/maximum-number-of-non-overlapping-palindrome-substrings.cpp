class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i];

            // Check palindrome of length k
            if (i - k + 1 >= 0) {
                int l = i - k + 1;
                int r = i;

                bool ok = true;

                while (l < r) {
                    if (s[l] != s[r]) {
                        ok = false;
                        break;
                    }
                    l++;
                    r--;
                }

                if (ok)
                    dp[i + 1] = max(dp[i + 1], dp[i - k + 1] + 1);
            }

            // Check palindrome of length k + 1
            if (i - k >= 0) {
                int l = i - k;
                int r = i;

                bool ok = true;

                while (l < r) {
                    if (s[l] != s[r]) {
                        ok = false;
                        break;
                    }
                    l++;
                    r--;
                }

                if (ok)
                    dp[i + 1] = max(dp[i + 1], dp[i - k] + 1);
            }
        }

        return dp[n];
    }
};