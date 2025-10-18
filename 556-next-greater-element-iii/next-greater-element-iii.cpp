class Solution {
public:
    void swap(char &a, char &b){
        char temp = a;
        a = b;
        b = temp;
    }
    void find_ele(int i , string &s, int n){
        int idx = i;
        int temp = s[i+1] - 'a';
        int src = s[i] - 'a';
        for(int j = i+1 ; j < n ; j++){
            if(src < (s[j] - 'a') && (s[j] - 'a') <= temp){
                temp = s[j] - 'a';
                idx = j;
            }
        }
        cout<<"abc"<<endl;
        swap(s[i], s[idx]);
        sort(s.begin() + i + 1 , s.end());
        // return;
    }

    long nextGreaterElement(int n) {
        if(n<10){
            return -1;
        }
        string stt = to_string(n);
        int sz = stt.size();
        int i= sz-2;
        while(i>=0){
            if((stt[i+1] - 'a') > (stt[i] - 'a')){
                break;
            }
            i--;
        }
        if(i>=0){
        find_ele(i, stt, sz);
        long ans = stol(stt);
        return ans > INT_MAX ? -1 : ans;}
        return -1;
    }
};