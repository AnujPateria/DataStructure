class Solution {
public:

    int d_a[4] = {1, -1, 0, 0};
    int d_b[4] = {0, 0, 1, -1};

    int solve(int i, int j, int n, int m,  vector<vector<int>>&arr, vector<vector<int> > &dp){
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int maxLen = 1;
        for(int d = 0 ; d < 4 ; d++){
            int x = i + d_a[d];
            int y = j + d_b[d];
            if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] > arr[i][j]){
                maxLen = max(maxLen, 1 + solve(x, y, n, m, arr, dp));
            }
        }
        return dp[i][j] = maxLen;
    }

    int longestIncreasingPath(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int ans = 0;
        vector<vector<int> > dp(n, vector<int> (m, -1)) ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                ans = max(ans, solve(i, j, n, m, arr, dp));
            }
        }
        return ans;
    }
};