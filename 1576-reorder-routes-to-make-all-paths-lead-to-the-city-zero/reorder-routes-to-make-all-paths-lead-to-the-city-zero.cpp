class Solution {
public:
    void bfs(int node, int n , vector<vector<pair<int, int>>> &vec, int &ans) {
        queue<int> qu;
        vector<bool> vis(n , false) ;
        qu.push(node);
        vis[0] = true;

        while(!qu.empty()) {
            int st = qu.front();qu.pop();

            for(auto adj : vec[st]) {
                if(!vis[adj.first]) {
                    ans+=adj.second;
                    vis[adj.first] =true;
                    qu.push(adj.first);
                }

            }

        }

    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> vec(n);
        for(int i = 0 ; i < connections.size() ; i++) {
            vec[connections[i][0]].push_back({connections[i][1], 1});
            vec[connections[i][1]].push_back({connections[i][0], 0});
        }
        int ans = 0;
        bfs(0, n, vec, ans);
        return ans;


    }
};