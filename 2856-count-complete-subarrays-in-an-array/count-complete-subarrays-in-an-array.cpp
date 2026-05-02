class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int sz = mp.size();
        unordered_map<int, int> mpp;
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            mpp[nums[i]]++;
            if(mpp.size() == sz){
                // ans++;
                unordered_map<int, int> temp = mpp;
                for(int j = 0 ; j <= i - sz + 1 ; j++){
                    temp[nums[j]]--;
                    if(temp.size() == sz){
                        ans++;
                    }
                    if(temp[nums[j]] == 0){
                        temp.erase(nums[j]);
                    }
                    
                    
                }
                // temp.clear();
            }
        }
        return ans;
    }
};