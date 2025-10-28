class Solution {
public:

    bool isValid(string s){
        stack<char>  st;
        // st.push(s[0]);
        for(int i = 0 ; i < s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                return false;
            }
        }
        return true;
    }


    // bool isValid(string s, stack<char> st, int i ){
    //     if(i== s.size()){
    //         return st.empty();
    //     }
    //     if(s[i] == '('){
    //         st.push('(');
    //     }
    //     else if(!st.empty() && st.top() == '('){
    //         st.pop();
    //     }
    //     else{
    //         return false;
    //     }
    //     return isValid(s, st, i+1);
    //     // if(isValid(s, st, i+1)) return true;

    //     // return true;
    // }   
    void solve(string s, vector<string> &ans, int idx){
        if(idx == s.length()){
            return ;
        }
        // stack<char> st;
        if(isValid(s)){
        ans.push_back(s);}
        if(next_permutation(s.begin(), s.end())){
            solve(s, ans, idx);
        }
    }

    vector<string> generateParenthesis(int n) {
        string st(n,'(');
        string en(n,')');
        st+=en;
        vector<string> ans;

        solve(st, ans, 0);
        return ans;
    }
};