class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int x : nums){
            mp[x]++;
            
        }
       
        int count = 0;
        for(int x : nums){
            int rem = k -x;
            if(rem == 0){
                continue;
            }
            if(mp.find(x)!= mp.end()){
                mp[x]--;
                if(mp[x] == 0){
                    mp.erase(x);
                }
                if(mp.find(k-x) != mp.end()){
                    mp[k-x]--;
                    count++;
                    if(mp[k-x] == 0){
                    mp.erase(k-x);
                }
                }
                
                
            }
        }
        return count;
    }
};