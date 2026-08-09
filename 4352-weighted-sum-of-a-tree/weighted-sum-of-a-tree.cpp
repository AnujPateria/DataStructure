class Solution {
public:

//  function<int(int)> getDepth = [&](int node) {
//             if (depth[node] != 0)
//                 return depth[node];

//             return depth[node] = getDepth(parent[node]) + 1;
//         };

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        long long ans = 0;
        vector<long long> depth(n, 0);
        depth[0] = 1;
        long long max_depth = 1;

        function<int(int) > getDepth = [&] (int node){
            if(depth[node] != 0){
                return depth[node];
            }
            return depth[node] = getDepth(parent[node]) + 1;
        };

        for(int i = 1; i < n; i++){
            depth[i] = getDepth(i);
            max_depth = max(max_depth, depth[i]);
        }
     
        for(int i = 0 ; i < n; i++){
            long long num = 1LL * nums[i];
            ans += (num *  (max_depth - depth[i] + 1));
        }
        
        return ans;
    }
};