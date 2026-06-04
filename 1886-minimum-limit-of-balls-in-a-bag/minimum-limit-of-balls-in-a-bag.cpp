class Solution {
public:

    bool valid(vector<int> &nums, int &mid, int &opr){
        long long count = 0;
        
        for(int num : nums){
            count += ((num - 1) / mid);
            if(count > opr){
                return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int opr) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while(low < high){
            int mid = low + (high - low)/2;
            if(valid(nums, mid, opr)){
                high = mid;
            }   
            else{
                low = mid + 1;
            }
        }
        return low;

        
    }
};