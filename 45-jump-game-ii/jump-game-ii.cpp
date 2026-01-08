class Solution {
public:
    int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;

    queue<int> q;
    q.push(0);

    int jumps = 0;
    vector<bool> visited(nums.size(), false);
    visited[0] = true;

    while (!q.empty()) {
        int size = q.size();
        jumps++;

        while (size--) {
            int idx = q.front();
            q.pop();

            int max_reach = idx + nums[idx];
            if (max_reach >= nums.size() - 1)
                return jumps;

            for (int i = idx + 1; i <= max_reach; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    return 0;
}

};