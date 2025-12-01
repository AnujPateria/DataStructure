class Solution {
public:


    void dfs(vector<vector<int>>& a, vector<bool> &vis, int i){
       
        vis[i] = true;
        for(int key : a[i]){
            if(!vis[key]){
                vis[key] = true;
                dfs(a, vis, key);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n , false);
        dfs(rooms, vis, 0);
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;

    }
};