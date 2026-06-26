class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int i, int j, int n, vector<string> &board){
        for(int row = 0 ; row <= i ; row++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        int row = i, col = j;
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        row = i;
        col = j;
        while(row >= 0 && col < n){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }

    void solve(int i, int n, vector<string> &board){
        if(i == n) {
            ans.push_back(board);
            return; 
        }
        for(int col = 0; col < n; col++){
            if(isSafe(i, col, n, board)){
                board[i][col] = 'Q';
                solve(i+1, n, board);
                board[i][col] = '.';
            }   
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        solve(0, n, board);
        return ans;
    }
};