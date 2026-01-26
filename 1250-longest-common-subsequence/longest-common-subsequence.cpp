class Solution {
public:
    vector<vector<int>> dp;
    int solve(string &s1, string &s2, int i, int j){
        if(i==0 || j == 0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i-1] == s2[j-1]){
            return  dp[i][j] = 1 + solve(s1, s2, i-1, j-1);
        }
        else{
            return dp[i][j] = max(solve(s1, s2, i-1, j), solve(s1, s2, i, j-1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int x = text1.length();
        int y = text2.length();
        dp.assign(x+1, vector<int> (y+1, -1));
        return solve(text1, text2, x, y);
    }
};