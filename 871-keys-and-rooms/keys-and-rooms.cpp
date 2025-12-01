class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vec(rooms.size(), false);
        queue<int> qu;
        vec[0] = true;
        for(int i = 0 ; i < rooms[0].size(); i++){
            qu.push(rooms[0][i]);
            vec[rooms[0][i]] = true;
        }
        while(!qu.empty()){
            int val = qu.front();
            qu.pop();
            for(int i = 0 ; i < rooms[val].size(); i++){
                if(!vec[rooms[val][i]]){
                    vec[rooms[val][i]] = true;
                    qu.push(rooms[val][i]);
                }
            }
        }
        for(int i = 0 ; i < rooms.size(); i++){
            if(vec[i] == false){
                return false;
            }
        }
        return true;
    }
};