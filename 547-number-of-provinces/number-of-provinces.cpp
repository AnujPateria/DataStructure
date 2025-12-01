class Solution {
public:
    void find_adj(vector<bool> &vis, vector<vector<int>> & iC, int ii){
        // int ans = 0;
        // vector<vector<bool>>  vis(iC.size(), vector<bool>(iC.size(), false));
        // vector<vector<bool>> vis(iC.size(), vector<bool>(iC.size(), false));

        // memset(vis, false, sizeof(vis.size()))
        queue<int> qu;
        qu.push(ii);
        vis[ii] = true;
        // int i = 0 ;
        // int j = 0 ;
        while(!qu.empty()){
            int val = qu.front();qu.pop();
            for(int i = 0 ; i < vis.size(); i++){
                if(iC[val][i] == 1 && !vis[i]){
                    // if(val != i){
                    //     continue;
                    // }
                    vis[i] = true;
                    // vis[val] = true;
                    qu.push(i);
                }
            }
            // if(qu.empty()){
            //     qu.push(val + 1);
            //     ans++;
            // }
        }
    }
        // return ans;/
    int findCircleNum(vector<vector<int>>& iC) {
        int ans = 0;
        vector<bool> vis(iC.size(), false);
        for(int i = 0 ; i < iC.size(); i++){
            if(!vis[i]){
                ans++;
                find_adj(vis, iC, i);
            }
        }
        return ans;
    }
};