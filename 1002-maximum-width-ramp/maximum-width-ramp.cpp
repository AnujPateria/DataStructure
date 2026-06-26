class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i = n - 1; i >= 0 ; i--){
            if(st.empty() || nums[st.top()] < nums[i]){
                st.push(i);
            }
        }
        int ans = 0;
        for(int i = 0 ; i< nums.size(); i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                ans = max(ans, st.top() - i);
                st.pop();
            }
        }
        return ans;

    }
};