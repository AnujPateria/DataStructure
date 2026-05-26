class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& tt, int k) {
        int n = tt.size();
        if (n == 0) return {};
        
        vector<int> ans;
        deque<int> d; // This will store INDICES
        //front has big end has small
        for(int i = 0; i < n; i ++){
            while (!d.empty() && tt[i] > tt[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
            if (i >= k-1){
                //the window has k elements now - have to remove i - k element
                if (d.front() == i - k){
                    d.pop_front();
                }
            ans.push_back(tt[d.front()]);
            }
        }
        return ans;

    }
};