class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int st = 1;
        vector<int> vec(1e5 + 2, false);
        int count = 1;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > 0 && nums[i] < 1e5 + 2){
                vec[nums[i]] = true;
            }
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(!vec[count++]){
                return count - 1;
            }
        }
        return count ;

    }
};