class Solution {
public:
vector<vector<int>> dp;
    int solve(int i, int j, int n, int m,vector<vector<int>>&obj){
        // if(obj[i][j] == 1){
        //     return 0;
        // }

        if(i == n - 1 && j == m -1 && obj[i][j] == 0){
            return 1;
        }
       
        if(i>=n || j>=m){
            return 0;
        }
        if(obj[i][j] == 1){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        
        return dp[i][j]=solve(i+1, j, n, m, obj) + solve(i, j+1, n, m, obj);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int n = obstacleGrid.size();
            int m = obstacleGrid[0].size();
        dp.assign(n+1 ,vector<int> (m+1, -1));
        return solve(0, 0, n, m, obstacleGrid);
    
    }
};