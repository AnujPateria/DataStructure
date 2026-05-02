class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int left = 0;
        int ans = 0;
        unordered_map<int, int> mp;
        for(int right = 0 ; right < nums.size(); right++){
            mp[nums[right]]++;
            while(st.size() == mp.size()){
                ans+=(nums.size() - right);
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
        }
        return ans;
    }
};