class Solution {
public:
vector<vector<int>> dp;

    bool checkValue(int x, int y, int limit){
        return abs(x - y) <= limit;
    }
    
    bool check(int idx, int prev_row, vector<vector<int>>&grid, int limit){
        for(int j = 0; j < grid.size(); j++){
            if(!checkValue(grid[j][idx] , grid[j][prev_row], limit)) {
                return false;
            }
        }
        return true;
    }

    int solve(int idx, int prev_row, vector<vector<int> > &grid, int limit){
        if(idx >= grid[0].size()){
            return 0;
        }
        if(dp[idx][prev_row + 1] != -1) {
            return dp[idx][prev_row + 1];
        }
        int take = 0;

        if(prev_row == -1 || check(idx, prev_row, grid, limit)){
            take = 1 + solve(idx + 1, idx, grid, limit);
        }
        int notTake = solve(idx + 1, prev_row, grid, limit);

        return dp[idx][prev_row + 1] = max(take, notTake);
    }

    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        int prev_row = -1;
        int n = grid[0].size();

        dp.assign(n + 1, vector<int> (n + 1, -1));
        return solve(0, prev_row, grid, limit);
    }
};



