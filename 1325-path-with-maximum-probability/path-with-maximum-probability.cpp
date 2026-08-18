class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double> > >adj(n);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<pair<double, int>, vector<pair<double, int> > > pq;
        pq.push({1.0, start_node});
        vector<double> dist(n+1, 0.0);
        dist[start_node] = 1.0;
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            double d = node.first;
            int u = node.second;
            if(d < dist[u]){
                continue;
            }
            for(auto [v, w] : adj[u]){
                if(d * w > dist[v]){
                    dist[v] = d * w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[end_node];


    }
};