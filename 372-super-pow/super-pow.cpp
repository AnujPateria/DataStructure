class Solution {
public:
    const int MOD = 1337;

    int modPow(int base, int exp) {
        base %= MOD;
        int result = 1;

        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }

            base = (base * base) % MOD;
            exp = exp / 2;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {
        a %= MOD;
        int ans = 1;

        for (int digit : b) {
            ans = (modPow(ans, 10) * modPow(a, digit)) % MOD;
        }

        return ans;
    }
};