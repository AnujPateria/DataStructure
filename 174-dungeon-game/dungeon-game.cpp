class Solution {
public:
    vector<vector<int>> dp;

    int dfs(int i, int j, int n, int m, vector<vector<int>>&temp){
        if(i>=n || j>= m){
            return INT_MAX;
        }
        if(i==n-1 && j==m-1){
            return max(1, 1-temp[i][j])  ;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int left = dfs(i+1, j, n, m, temp);
        int right = dfs(i, j + 1, n, m, temp);

        return dp[i][j] = max(1, min(left, right) - temp[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& temp) {
        int n = temp.size(); int m = temp[0].size();
        dp.assign(n, vector<int>(m, -1));
        return dfs(0,0,n,m,temp);
    }
};