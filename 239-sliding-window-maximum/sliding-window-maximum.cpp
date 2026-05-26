class Solution {
public:

    vector<int> seg;
    vector<int> arr;

    void build(int idx, int low, int high){
        if(low == high){
            seg[idx] = arr[low];
            return ;
        }
        int mid = (low+high)/2;
        build(2*idx + 1, low, mid);
        build(2*idx + 2, mid + 1, high);
        seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
    }

    int query(int idx, int low, int high, int i, int j){
        if( i > high || j < low){
            return INT_MIN;
        }
        if(j >= high && i <= low){
            return seg[idx];
        }
        int mid = (low + high)/2;
        int left = query(2*idx + 1, low, mid, i, j);
        int right = query(2*idx + 2, mid + 1, high, i, j);
        return max(left, right);
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        seg.assign(4*n, INT_MIN);
        vector<int> ans;
        arr = nums;
        build(0, 0, n-1);
        for(int i = 0; i <= n - k ; i++){
            int res = query(0, 0, n-1, i, k + i - 1);
            ans.push_back(res);
        }
        return ans;
    }
};