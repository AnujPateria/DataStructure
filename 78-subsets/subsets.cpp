class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(nums , ans, sub, 0);
        return ans;
    }
    private:
    void solve(vector<int> & nums, vector<vector<int>>&ans, vector<int> sub, int idx){
        ans.push_back(sub);
        for(int i = idx; i< nums.size(); i++){
            sub.push_back(nums[i]);
            solve(nums , ans, sub, i+1);
            sub.pop_back();
        }
    }
    
};