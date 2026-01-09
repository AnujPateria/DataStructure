class Solution {
public:
    int numSquares(int n) {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(n);
    visited[n] = true;

    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        level++;

        while (size--) {
            int curr = q.front();
            q.pop();

            for (int i = 1; i * i <= curr; i++) {
                int next = curr - i * i;
                if (next == 0) return level;

                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
    }
    return level;
}

};