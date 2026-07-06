class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int mod = 1e9 + 7;

        long long low = 1;
        long long high = 1LL * n * min(a, b);

        long long lcm = (1LL * a * b) / __gcd(a, b);

        while (low < high) {
            long long mid = low + (high - low) / 2;

            long long count = mid / a + mid / b - mid / lcm;

            if (count >= n) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low % mod;
    }
};