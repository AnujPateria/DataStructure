class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i, int j, int n, int m, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            // right, down
            return INT_MAX;
        }

        // temp += grid[i][j];

        if (i == n - 1 && j == m - 1) {
            return grid[i][j];
            // temp = 0;
        }
        // right

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = grid[i][j] + min(dfs(i + 1, j, n, m, grid),
                                           dfs(i, j + 1, n, m, grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int i = 0, j = 0;
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MAX;
         dp.assign(n, vector<int>(m, -1));
        return dfs(i, j, n, m, grid);
        return dp[0][0] == -1? 0 : dp[0][0];
    }
};