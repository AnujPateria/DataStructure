class Solution {
public:
    struct cmp {
        bool operator() (const pair<int, int> &a,const pair<int,int> &b){
            return a.second > b.second;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i = 0 ; i < times.size(); i++){
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int, int> , vector<pair<int, int>>, cmp > pq;
        pq.push({k, 0});
        vector<int> dist(n+1, INT_MAX); dist[k] = 0;
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            int u = node.first;
            int d = node.second;
            if(d > dist[u]){
                continue;
            }
            for(auto [v, w] : adj[u]){
                if(d + w < dist[v]){
                    dist[v] = d + w;
                    pq.push({v, dist[v]});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if (dist[i] == INT_MAX) {
                return -1 ;}
            ans = max(ans, dist[i]);
        }
        return ans;


    }
};