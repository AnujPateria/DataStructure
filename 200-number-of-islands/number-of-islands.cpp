class Solution {
public:

    int dir_x[4] = {1, -1, 0, 0};
    int dir_y[4] = {0, 0, 1, -1};

    bool issafe(int x, int y, int n, int m, vector<vector<int>> &vis){
        if(x >= 0 && y >= 0 && x < n && y < m && !vis[x][y]){
            return true;
        }
        return false;
    }

    void dfs(int i, int j, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &vis){
        
        
     
        for(int k = 0; k< 4; k++){
            int nx = dir_x[k] + i;
            int ny = dir_y[k] + j;
            if(issafe(nx, ny, n, m, vis) && grid[i][j] == '1'){
                vis[nx][ny] = 1;
                dfs(nx, ny, n, m, grid, vis);
            }
        }


    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > vis(n, vector<int> (m, 0));
        int ans = 0;
        for(int i = 0; i < n ;i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    vis[i][j] = 1;
                    dfs(i, j, n, m, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};