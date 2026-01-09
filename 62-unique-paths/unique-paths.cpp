class Solution {
public:
vector<vector<int>>dp;

    int find_path(int i, int j, int& count, int m, int n) {
        if(i >= m || j >= n){
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            // count++;

            return 1;
        }
        if(dp[i][j] != -1){
             return dp[i][j];
        }
        return dp[i][j]=find_path(i, j + 1, count, m, n )+find_path(i + 1, j, count, m, n );
        
    }

    int uniquePaths(int m, int n) {
        int count = 0;
        dp.assign(m, vector<int>(n, -1));

        return find_path(0, 0, count, m, n);
        // return count;
    }
};