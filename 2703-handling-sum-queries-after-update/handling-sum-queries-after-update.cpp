class Solution {
public:
    vector<int> seg;
    vector<int> lazy;
    vector<int> arr1;
    vector<int> arr2;



    void build(int idx, int low, int high, vector<int> &arr1){
        if(low == high){
            seg[idx] = arr1[low];
            return;
        }
        int mid = low + (high-low) / 2;
        build(2*idx + 1, low, mid, arr1);
        build(2*idx + 2, mid + 1, high, arr1);
        seg[idx] = seg[2*idx + 1] + seg[2*idx + 2];
    }

    void update(int node, int start, int end, int l, int r){
        if(lazy[node] != 0){
            seg[node] = (end - start + 1) - seg[node];
            if(start != end){
                lazy[2*node + 1] = !lazy[2*node + 1];
                lazy[2*node + 2] = !lazy[2*node + 2];
            }
            lazy[node] = 0;
        }
        if(start > r || end < l){
            return ;
        }
        if(start >= l && end <= r){
            seg[node] = (end - start + 1) - seg[node];
            if(start != end){
                lazy[2*node + 1] = !lazy[2*node + 1];
                lazy[2*node + 2] = !lazy[2*node + 2];
            }
            return;
        }
        int mid = (start + end)/2;
        update(2*node + 1, start, mid , l, r);
        update(2*node + 2, mid + 1, end, l, r);
        seg[node] = seg[2*node + 1] + seg[2*node + 2];
    }
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size() ;

        seg.resize(4*n, 0);
        lazy.assign(4*n, 0);
        build(0, 0, n - 1, nums1);

vector<long long> ans;

        long long sum = 0;
        for(int i = 0 ; i < n ; i++) sum += nums2[i];

        for(int i = 0 ; i < queries.size() ; i++){
            if(queries[i][0] == 1){
                update(0, 0, n - 1, queries[i][1], queries[i][2]);
            }
            else if(queries[i][0] == 2){
                sum+= ( 1LL * seg[0] * queries[i][1]);
            }
            else{
                ans.push_back(sum);
            }
        }
        return ans;

        
        
    }
};


/*
1.
















*/