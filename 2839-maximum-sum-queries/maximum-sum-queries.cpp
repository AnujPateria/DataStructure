class Solution {
public:
    vector<int> seg;

    int query(int idx, int i, int j, int st, int en){
        if(i>en || j<st){
            return INT_MIN;
        }
        if(i<=st && j>=en){
            return seg[idx];
        }
        int mid = (st + en)/2;
        return max(query(2*idx + 1, i, j, st, mid), query(2*idx + 2, i, j, mid + 1, en));
    }
    void update(int pos, int val, int idx, int st, int en){
        if(st == en){
            seg[idx] = max(seg[idx], val); 
            return;
        }
        int mid = (st + en)/2;
        if(pos <= mid){
            update(pos, val, 2*idx + 1, st , mid );
        }
        else{
            update(pos, val , 2*idx + 2, mid + 1, en);
        }
        seg[idx] = max(seg[2*idx + 1],seg[2*idx + 2]);
    }

    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        int n = nums1.size();
        
        for(int i = 0 ; i < n; i++){
            arr.push_back({nums1[i], nums2[i]});
        }
         sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });

        set<int> st;
        for(auto &num : arr){
            st.insert(num.second);
        }
        for(auto &qu: queries){
            st.insert(qu[1]);
        }
        vector<int> all(st.begin(), st.end());
        int m = all.size();

        seg.resize(4*all.size(), INT_MIN);

        // unordered_map<int, int> comp;
        // for(int i = 0 ; i< all.size(); i++){
        //     comp[all[i]] = i;
        // }

        vector<vector<int>> q2;

        for(int i = 0 ; i < queries.size(); i++){
            q2.push_back({queries[i][0], queries[i][1], i});
        }

        sort(q2.begin(), q2.end(), [] (auto &a, auto &b){
            return a[0] > b[0];
        });


        vector<int> ans(queries.size() , -1);
        int j = 0 ;

        for(auto &q: q2){
            int xi = q[0];
            int yi = q[1];
            int pos = q[2];
            while(j<n && arr[j].first >= xi){
                int x = arr[j].first;
                int y = arr[j].second;
                
                int idx = lower_bound(all.begin(), all.end(), y) - all.begin();

                update(idx, x+y,0, 0, m - 1);
                j++;

            }

            auto it = lower_bound(all.begin(), all.end(), yi);
            
                if(it != all.end()){
                    int left = it - all.begin();
                    int res = query(0, left, m-1, 0,  m-1);
                    ans[pos] = (res == INT_MIN ? -1: res);
                }
            
            
        }
        return ans;


        
    }
};