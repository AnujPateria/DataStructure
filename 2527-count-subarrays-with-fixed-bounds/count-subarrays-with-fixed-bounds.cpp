class Solution {
public:

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
       
        deque<int> minq, maxq;
        int left = 0;

        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] < minK || nums[i] > maxK){
                minq.clear();
                maxq.clear();
                left = i + 1;
                continue;
            }
            while(!minq.empty() && nums[minq.back()] >= nums[i]){
                minq.pop_back();
            }
            minq.push_back(i);
            while(!maxq.empty() && nums[maxq.back()] <= nums[i]){
                maxq.pop_back();
            }
            maxq.push_back(i);
            if(nums[minq.front()] == minK && nums[maxq.front()] == maxK ){
                int end = min(minq.front(), maxq.front());
                ans += (end - left + 1);
            }
        }
        return ans;
    }
};