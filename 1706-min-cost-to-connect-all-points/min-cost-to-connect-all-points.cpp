class Solution {
public:
    vector<vector<int>> adj;
    vector<int> par, rank;
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
    void unionByRank(int u, int v){
        int paru = find(u);
        int parv = find(v);
        if(rank[paru] == rank[parv]){
            par[paru] = parv;
            rank[parv]++;
        }
        else if(rank[paru] > rank[parv]){
            par[parv] = paru;
        }
        else {
            par[paru] = parv;
        }
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        par.resize(n);
        rank.resize(n, 0);
        for(int i = 0 ; i< n; i++){
            par[i] = i;
        }
        for(int i = 0; i< points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj.push_back({dist, i, j});
            }
        }
        sort(adj.begin(), adj.end());
        int cost = 0;
        for(int i =0 ;i < adj.size(); i++){
            int u = adj[i][1];
            int v = adj[i][2];
            if(find(u) != find(v)){
                unionByRank(u, v);
                cost += adj[i][0];
            }
        }
        return cost;

    }
};