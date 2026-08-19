class Solution {
public:

    vector<vector<pair<int, int>> > adj;
    int solve(int n, int src, int dts, int k){
        vector<vector< int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0; 
        priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int> >>, greater<pair<int, pair<int, int> >>> pq; 
        pq.push({0, {0, src}});
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            int d = node.first;
            int u = node.second.second;
            int stops = node.second.first;
            if( u == dts){
                return d;
            }
            if(stops > k){
                continue;
            }
            for(auto ele : adj[u]){
                int v = ele.first;
                int w = ele.second;
                int newStops = stops + 1;
                int newCost = d + w;
                if(newCost < dist[v][newStops] && newStops <= k + 1){
                    dist[v][newStops] = newCost;
                    pq.push({newCost, {newStops, v}});
                }
            }
        }
        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        adj.resize(n);
        for(int i = 0 ; i < flights.size(); i++){
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adj[u].push_back({v, w});
        }
        return solve(n, src, dst, k);

        // return (ans.second <= k && ans.first != INT_MAX ? ans.first : -1);

    }
};