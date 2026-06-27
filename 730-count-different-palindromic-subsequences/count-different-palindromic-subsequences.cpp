class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp;

    long long solve(int i, int j, string &s) {
        if (i > j) return 0;
        if (i == j) return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans;

        if (s[i] == s[j]) {
            int low = i + 1;
            int high = j - 1;

            while (low <= high && s[low] != s[i])
                low++;

            while (low <= high && s[high] != s[j])
                high--;

            if (low > high) {
                // No same character inside
                ans = 2 * solve(i + 1, j - 1, s) + 2;
            }
            else if (low == high) {
                // One same character inside
                ans = 2 * solve(i + 1, j - 1, s) + 1;
            }
            else {
                // More than one same character inside
                ans = 2 * solve(i + 1, j - 1, s)
                      - solve(low + 1, high - 1, s);
            }
        }
        else {
            ans = solve(i + 1, j, s)
                + solve(i, j - 1, s)
                - solve(i + 1, j - 1, s);
        }

        ans = (ans % MOD + MOD) % MOD;
        return dp[i][j] = ans;
    }

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        dp.assign(n, vector<long long>(n, -1));
        return solve(0, n - 1, s);
    }
};