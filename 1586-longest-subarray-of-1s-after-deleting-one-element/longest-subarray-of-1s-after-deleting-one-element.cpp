class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> col;
        int count = 0;
        bool ch = true;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] == 0){
                ch = false;
                col.push_back(count);
                col.push_back(0);
                count = 0;
            }
            else{
                count++;
            }
        }
        if(count!=0){
        col.push_back(count);}
        if(ch){
            return count-1;
        }
        int ans = 0;
        for(int i = 0 ; i < col.size(); i++){
            if(col[i] == 0){
                int temp = 0;
                if(i-1 >=0 ){
                    temp+=col[i-1];
                }
                if(i+1 < col.size()){
                    temp+=col[i+1];
                }
                ans = max(ans , temp);
            }
        }
        return ans;

    }
};