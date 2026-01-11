class Solution {
public:

vector<vector<int>> dp;

    int dfs(int i, int j, int n, int m, vector<vector<int>>& ob){
        if(i < 0 || i >= n || j < 0 || j>= m ){
            return 0;
        }
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(ob[i][j] == 1){
            return 0;
        }
        return dp[i][j] = dfs(i+1, j, n, m, ob) +  dfs(i, j+1, n, m, ob);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int n = ob.size();
        int m = ob[0].size();
        dp.assign(n, vector<int>(m , -1));
        if(ob[n-1][m-1] == 1){
            return 0;
        }
        return dfs(0,0,n,m,ob);
    }
};