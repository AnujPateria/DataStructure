class Solution {
public:
    const int mod = 1337;

    int find_b_power(int a, int ele){
        int prev = 1;
        for(int j = 1 ; j <= ele; j++){
            prev = (prev * a) % mod;
        }
        return prev;
    }

    int superPow(int a, vector<int>& b) {
        a = a % mod;
        int ans = 1;
        // int count = 1;
        // b[b.size() - 1] = find_b_power(a, b[b.size() - 1]);
        // int prev = a;
        for(int i = 0; i < b.size(); i++){
            // int ele = b[i];
            // int temp = 1;

            // for(int j = 1; j <= 10 ; j++){
            //     temp = (temp * prev) % mod;
            // }

            // prev = temp;
            ans = (find_b_power(ans, 10) * find_b_power(a, b[i])) % mod;

        }
        return ans;
    }
};