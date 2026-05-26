class Solution {
public:

    const int MOD = 1e9 + 7;

    vector<int> seg;

    // Update frequency
    void update(int idx, int low, int high,
                int pos){

        if(low == high){

            seg[idx]++;

            return;
        }

        int mid = (low + high)/2;

        if(pos <= mid){

            update(2*idx + 1,
                   low,
                   mid,
                   pos);
        }
        else{

            update(2*idx + 2,
                   mid + 1,
                   high,
                   pos);
        }

        seg[idx] =
            seg[2*idx + 1]
          + seg[2*idx + 2];
    }

    // Range sum query
    int query(int idx, int low, int high,
              int l, int r){

        // No overlap
        if(l > high || r < low){
            return 0;
        }

        // Complete overlap
        if(l <= low && high <= r){
            return seg[idx];
        }

        int mid = (low + high)/2;

        return query(2*idx + 1,
                     low,
                     mid,
                     l,
                     r)

             +

               query(2*idx + 2,
                     mid + 1,
                     high,
                     l,
                     r);
    }

    int createSortedArray(vector<int>& instructions) {

        int mx =
            *max_element(instructions.begin(),
                         instructions.end());

        seg.assign(4*(mx + 1), 0);

        long long ans = 0;

        for(int i = 0; i < instructions.size(); i++){

            int x = instructions[i];

            // Count smaller elements
            int less =
                query(0, 0, mx,
                      0, x-1);

            // Count greater elements
            int greater =
                query(0, 0, mx,
                      x+1, mx);

            ans =
                (ans + min(less, greater))
                % MOD;

            // Insert current element
            update(0, 0, mx, x);
        }

        return ans;
    }
};