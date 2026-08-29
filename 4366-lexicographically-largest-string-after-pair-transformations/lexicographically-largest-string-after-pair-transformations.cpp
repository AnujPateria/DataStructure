class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        ans.reserve(nums.size());

        for (int num : nums) {
            string temp;

            for (int bit = 0; bit < 27; bit++) {
                if (num & (1 << bit)) {
                    if (bit < 26) {
                        temp += char('a' + bit);
                    } else {
                        temp += "zz";
                    }
                }
            }

            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        return ans;
    }
};