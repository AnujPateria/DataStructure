class NumArray {
public:
    vector<int>seg;
    vector<int> arr;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.assign(4*n, 0);
        arr = nums;
        build(0, 0, n-1);
    }

    void build(int node, int st, int en){
        if(st == en){
            seg[node] = arr[st];
            return;
        }
        int mid = (st + en)/2;
        build(2*node + 1, st, mid);
        build(2*node + 2, mid + 1, en);

        seg[node] = seg[2*node + 1] + seg[2*node + 2];
    }
    int query(int node, int i, int j, int st, int en){
        if(i>en || j < st){
            return 0;
        }
        if(i <= st && j>=en){
            return seg[node];
        }
        int mid = (st + en)/2;
        return query(2*node + 1, i, j, st, mid) + query(2*node + 2, i, j, mid + 1, en);
    }
    void updateQuery(int idx, int pos,  int val, int st, int en){

        if(st == en){
            seg[idx] = val;
            arr[pos] = val;
            return ;
        }

        int mid = (st + en)/2;
        if(pos <= mid){
            updateQuery(2*idx+1,pos,  val, st , mid);
        }
        else{
            updateQuery(2*idx+2,pos,  val, mid + 1, en);
        }
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }
    void update(int index, int val) {
        return updateQuery(0, index, val, 0, n-1);
    }
    
    int sumRange(int left, int right) {
        return query(0, left, right, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */