class Solution {

public:

// int ans = 0;
vector<vector<int>> dp;
    int solve(int i, int j, int n, int m, string&s1, string&s2, string emp){
        if(emp == s2){
            // emp = "";
            return 1;
        }
        if(i==n || j == m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int take = 0;
        if(s1[i] == s2[j]){
            take += solve(i+1, j+1, n, m, s1, s2, emp+s1[i]);
        }
        int notTake = solve(i+1, j, n, m, s1, s2, emp);
        return dp[i][j]=(take + notTake);
        
    }

    int numDistinct(string s, string t) {
        string emp = "";
        dp.assign(s.length(), vector<int> (t.length(), -1));
        return solve(0, 0, s.length(), t.length(), s, t, emp);
    }
};