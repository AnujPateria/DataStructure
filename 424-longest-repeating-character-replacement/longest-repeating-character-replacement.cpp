class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            int count = 0;
            int temp = 0;
            int j = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] != ch ) {
                    count++;
                }
                
                while (count > k && j <= i ) {
                    if (ch != s[j]) {
                        count--;
                    }
                    j++;
                }
                ans = max(ans, i - j + 1);
            }

            
        }
        return ans;
    }

}
;