class Solution {
public:

    void solve(vector<int> & nums, vector<int> sub, int idx, vector<vector<int>> & ans){
        

        if(idx == nums.size()){
            // sub.pop_back();
            ans.push_back(sub);
            return ;
        }
        
        sub.push_back(nums[idx]);
        solve(nums , sub, idx+1, ans);
        sub.pop_back();
        solve(nums, sub, idx+1, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(nums , sub, 0, ans);
        return ans;
    }
};