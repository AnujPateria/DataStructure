class Solution {
public:
    bool canJump(vector<int>& nums) {
        //indeex + ele > curr_idx
        int max_ele = INT_MIN;
        int idx = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                if(i == nums.size() - 1){
                    return true;
                }
                if(max_ele <= i ){
                    return false;
                    // continue;
                }
                
            }
            max_ele = max(max_ele, i + nums[i]);
        }
        return true;
    }
};