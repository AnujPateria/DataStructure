class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        if (n == 1) {
            return 1;
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        pq.push({1, 0, 0});
        int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        while (pq.size()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (d > dis[x][y])
                continue;
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 && d + 1 < dis[nx][ny]) {
                    dis[nx][ny] = 1 + d;
                    if (nx == n - 1 && ny == n - 1)
                        return dis[nx][ny];
                    pq.push({dis[nx][ny], nx, ny});
                }
            }
        }
        return -1;
    }
};