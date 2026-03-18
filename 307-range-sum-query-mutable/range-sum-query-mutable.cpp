class NumArray {
public:

    vector<int> seg;
    int n;

    void buildTree(vector<int> &nums, int idx, int i, int j){
        if(i == j){
            seg[idx] = nums[i];
            return ;
        }
        int mid = (i + j) / 2;
        buildTree(nums, 2*idx + 1, i, mid);
        buildTree(nums, 2*idx + 2, mid+1, j);
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];

    }

    NumArray(vector<int>& nums) {
        if(nums.size() > 0){
            n = nums.size();
            seg.resize(4*n);
            buildTree(nums, 0, 0, n-1);
        }
    }

    void updateTree(int idx, int low, int high, int curr, int val){
        if(low == high){
            seg[idx] = val;
            // arr[idx] = val;
            return;
        }
        int mid = (low + high)/2;
        if(curr <= mid){
            updateTree(2*idx + 1, low, mid, curr, val );
        }
        else{
            updateTree(2*idx + 2, mid+1, high, curr, val);
        }
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }
    
    void update(int index, int val) {
        if(n==0) return ;
        updateTree(0, 0, n-1, index, val);
    }
    int sumUpdate(int idx, int low, int high, int l, int r){
        if(low>=l && high<= r){
            return seg[idx];
        }

        if(low > r || high < l){
            return 0;
        }
        int mid = (low + high) /2;
        int left = sumUpdate(2*idx + 1, low, mid, l, r);
        int right = sumUpdate(2*idx + 2, mid+1, high, l, r);
        return left + right;
    }
    
    int sumRange(int left, int right) {
        if(n==0) return 0;
        return sumUpdate(0, 0, n-1, left, right);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */