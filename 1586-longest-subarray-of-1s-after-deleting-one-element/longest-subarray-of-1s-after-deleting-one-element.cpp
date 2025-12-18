class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //if all ones check seperately

        int ans = 0;
        bool ch = true;
        int prev = -1;

        int left = 0;
        int right = 0;

        for(int i = 0 ; i < nums.size(); i++){

            if(ch == false && nums[i] == 0){
                left = right;
                right = 0;
            }

            else if(nums[i] != 0 && ch == true){
                left++;
            }
            else if(nums[i] == 0){
                ch = false;
            }
            else if(ch == false && nums[i]!=0){
                right++;
            }

            ans = max(ans , left+right);
        }
        if(ch == true){
            ans = left -1;
        }
        return ans;

        
    }
};