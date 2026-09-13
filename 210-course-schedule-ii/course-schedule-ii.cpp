class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        vector<int> ans;

        queue<int> pq;
        for(int i = 0 ; i< pr.size(); i++){
            int x = pr[i][0]; int y = pr[i][1];
            adj[y].push_back(x);
            indeg[x]++;
        }
        for(int i = 0 ; i< n; i++){
            if(indeg[i] == 0){
                pq.push(i);
            }
        }
        int count = 0;
        while(!pq.empty()){
            int top = pq.front(); pq.pop();
            ans.push_back(top);
            count++;
            for(auto node : adj[top]){
                indeg[node]--;
                if(indeg[node] == 0){
                    pq.push(node);
                }
            }

        }
        vector<int> temp;
        return (count == n ? ans : temp);
    }
};