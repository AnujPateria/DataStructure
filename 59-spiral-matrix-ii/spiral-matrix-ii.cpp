class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1; 
        // int sz = bottom*right;
        vector<vector<int>> ans(n, vector<int> (n));
        int count = 1;
        while(left<=right || top <= bottom){
            for(int a = left ; a <= right ; a++){
                ans[top][a] = count;
                count++;
            }
            top++;
            if(top>bottom){
                // return ans;
                break;

            }
            for(int a = top ; a <= bottom ; a++){
                ans[a][right] = count;count++;
            }
            
            right--;
            if(left>right){
                // return ans;
                break;
            }
            for(int a = right ; a>=left ; a--){
                ans[bottom][a] = count;count++;
            }
            bottom--;
            if(top>bottom){
                // return ans;
                break;
            }
            for(int a = bottom ; a>=top ; a--){
                ans[a][left] = count;
                count++;
            }
            left++;
            if(left>right){
                // return ans;
                break;
            }
        }
        vector<vector<int>> temp(n, vector<int> (n));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < n ;j++){
                temp[i][j] = ans[i][j];
            }
        }
        
    return temp;
    }
};