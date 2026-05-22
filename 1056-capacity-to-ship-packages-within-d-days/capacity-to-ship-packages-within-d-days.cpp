class Solution {
public:

    bool isSolve(vector<int> &w, int days, int mid){
        int count = 1;
        int sum = 0;
        for(int num : w){
            if(num > mid){
                return false;
            }
            if(num + sum <= mid){
                sum+=num;
            }
            else{
                count++;
                sum = num;
            }
        }
        return count<=days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MIN;
        int right = 0;
        for(int num : weights){
            right += num;
            left = max(left, num);
        }
        
        int ans = right;

        while(left <= right){
            int mid = (left + right) / 2;
            if(isSolve(weights, days, mid)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};