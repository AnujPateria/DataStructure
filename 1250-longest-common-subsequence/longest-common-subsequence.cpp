class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, int n, int m, string &s1, string &s2){
        if(i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + solve(i+1, j+1, n, m, s1, s2);
        }
        return dp[i][j]  = max (solve(i+1, j, n, m, s1, s2) , solve(i, j+1, n, m, s1, s2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        dp.assign(n, vector<int> (m, -1));

        return solve(0, 0, text1.size(), text2.size(), text1, text2);
    }
};