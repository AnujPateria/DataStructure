class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n , -1);
        int count = 0;
        int i = 0;
        while(count<2 && i < n){
            while(!st.empty() && nums[st.top()] < nums[i]){
                if(ans[st.top()] == -1){
                    // cout<<nums[i]<<" ";
                    ans[st.top()] = nums[i];
                }
                st.pop();
            }
            if(st.empty() || nums[st.top()] >= nums[i]){
                // if(count == 1){
                //     count++;
                //     break;
                // }
                st.push(i);
            }
            i++;
            if(i == n){
                i = 0;
                count++;
            }
        }
        return ans;

    }
};