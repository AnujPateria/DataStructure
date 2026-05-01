class Solution {
public:
    int maxi = 1e5 + 7;
    vector<int> seg;
     vector<int> arr;

    // void build(int idx, int st, int en){
    //     if(st >= en){
    //         seg[idx] = arr[st];
    //         return;
    //     }
    //     int mid = (st + en) / 2;
    //     build(2*idx + 1, st, mid);
    //     build(2*idx + 2, mid + 1, en);

    //     seg[idx] = max(seg[2*idx + 1], seg[2*idx + 2]);
        
    // }
    int query(int idx, int i, int j, int st, int en){
        if(i>en || j < st){
            return 0;
        }
        if(i<=st && j>=en){
            return seg[idx];
        }
        int mid = (st + en) / 2;

        return max(query(2*idx + 1, i, j, st, mid), query(2*idx + 2, i, j, mid + 1, en));
    }
    void update(int idx, int st, int en, int pos, int val){
        if(st >= en){
            seg[idx] = max(seg[idx],val);
            // arr[idx] = val;
            return;
        }
        int mid = (st + en)/2;
        if(pos <= mid){
            update(2*idx + 1, st, mid , pos, val);
        }
        else{
            update(2*idx + 2, mid + 1, en, pos, val);
        }
        seg[idx] = max(seg[2*idx + 1] , seg[2*idx + 2]);
    }


    int lengthOfLIS(vector<int>& nums, int k) {
        seg.assign(4*maxi, 0);
        int ans = 0;
        // arr= nums;
        for(int num : nums){
            int left = max(1, num - k);
            int right = num - 1;
            int best = 0;
            if(left <= right){
                best = query(0, left, right, 0, 1e5);
            }
            int curr = best + 1;
            update(0, 0, 1e5, num, curr);

            ans = max(ans, curr);
        }
        return ans;
    }
};