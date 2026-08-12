class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        int st = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0 ; i < nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == k + 1){
                while(st <= i && mp[nums[i]] == k + 1){
                    mp[nums[st++]]--;
                }
            }
            ans = max(ans, i-st+1);
        }
        return ans;
    }
};