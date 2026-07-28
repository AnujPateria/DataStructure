class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> vec(27, 0);
        for(int i = 0 ; i < s.length(); i++){
            vec[(s[i] - 'a')]++;
        }
        string st;
        for(int i = 0 ; i < 26; i++){
            char ch = 'a' + i;
            int temp = 0;
            if(vec[i] % 2 != 0){
                temp++;
            }
            st += string((vec[i] - temp) / 2, ch);
            vec[i] = temp;
        }
        string rev = st;
        for(int i = 0 ; i < 26; i++){
            if(vec[i] == 1){
                st += ('a' + i);
            }
        }
        reverse(rev.begin(), rev.end());
        return st + rev;
        

    }
};