class Solution {
public:
    bool canFinish(int nc, vector<vector<int>>& pre) {
        vector<vector<int>>adj(nc);

        vector<int> indeg(nc, 0);

        for(auto ele : pre){
            adj[ele[1]].push_back(ele[0]);
            indeg[ele[0]]++;
        }

        queue<int> qu;
        for(int i = 0 ; i < nc ; i++){
            if(indeg[i] == 0){
                qu.push(i);
            }
        }
        int count = 0;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            count++;
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it] == 0){
                    qu.push(it);
                }
            }
        }
        return count == nc;
    }
};