class Solution {
public:

    // bool isValid(string s){
    //     stack<char>  st;
    //     // st.push(s[0]);
    //     for(int i = 0 ; i < s.length(); i++){
    //         if(s[i] == '('){
    //             st.push(s[i]);
    //         }
    //         else if(!st.empty() && st.top() == '('){
    //             st.pop();
    //         }
    //         else{
    //             return false;
    //         }
    //     }
    //     return true;
    // }


    bool isValid(string s, stack<char> st, int i ){
        if(i== s.size()){
            return st.empty();
        }
        if(s[i] == '('){
            st.push('(');
        }
        else if(!st.empty() && st.top() == '('){
            st.pop();
        }
        else{
            return false;
        }
        return isValid(s, st, i+1);
        // if(isValid(s, st, i+1)) return true;

        // return true;
    }   

    vector<string> generateParenthesis(int n) {
        string st;
        string en;
        for(int i = 0 ; i < n ; i++){
            st+='(';
            en+=')';
        }
        st+=en;
        sort(st.begin(), st.end());
        vector<string> vec;
        do{
            stack<char> s;
            if(isValid(st, s, 0))
                vec.push_back(st);
        }
        while(next_permutation(st.begin(), st.end()));
        return vec;
    }
};