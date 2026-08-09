class Solution {
    int maximalSquares(int i, int j, vector<vector<int>>& mat, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(mat[i][j] == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int l = maximalSquares(i, j-1, mat, dp);
        int up = maximalSquares(i-1, j, mat, dp);
        int diag = maximalSquares(i-1, j-1, mat, dp);

        return dp[i][j] = 1+ min({l, up, diag});
    }
    
    bool isPoss(int k, vector<vector<int>>& dp){
        int n = dp.size();
        int m = dp[0].size();
        int minRow = n, maxRow = -1;
        int minCol = m, maxCol = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[i][j] >= k){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);

                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }

        if(maxRow == -1)
            return false;

        return (maxRow - minRow >= k || maxCol - minCol >= k);
    }
public:
    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));

        for(int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < m ; j++){
                maximalSquares(i, j, mat, dp);        
            }
        }

        int l = 1;
        int r = min(m, n);
        int ans = 0;
        
        while(l <= r){
            int k = l + (r-l) / 2;

            if(isPoss(k, dp)){
                ans = k;
                l = k + 1;
            }else{
                r = k-1;
            }
        }

        return ans * ans;
    }
};