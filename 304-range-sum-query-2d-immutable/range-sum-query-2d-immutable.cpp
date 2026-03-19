class NumMatrix {
public:
    vector<vector<int>> seg;
    int n; int m;

    /*
    void buildTree(matrix, idx, st, en){
        if(st == en){
            seg[idx] = matrix[st];
            return;
        }
        int mid = st + en;
        buildTree(matrix, 2*idx + 1, st, mid);
        buildTree(matrix, 2*idx + 2, mid+1, en);
        seg[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
    }

    int query(matrix,  int str, int enr, int firstidx, int endidx){
        if(firstidx >= str && endidx <= )
    }
    FIRST_IDX >= l && LAST_IDX  <= r // completely cover array (ffull sum array)

    FIRST_IDX > R || last_idx < l // not even a single element cover the array



    */
// this we do for 1d array now for 2d first iterate x then iterate y


    void buildY(vector<vector<int>>&matrix, int nodeX, int stX, int enX){
        if(stX == enX){
            buildX(matrix, nodeX, stX, enX, 0, 0, m-1);
        }
        else{
            int mid = (stX + enX)/2;
            buildY(matrix, 2*nodeX + 1, stX, mid);
            buildY(matrix, 2*nodeX + 2, mid + 1, enX);

            buildX(matrix, nodeX, stX, enX, 0, 0, m-1);
        }

    }


    void buildX(vector<vector<int>>&matrix,int nodeX, int stX, int enX, int nodeY, int stY, int enY){
        if(stY == enY){
            if(stX == enX){
                seg[nodeX][nodeY] = matrix[stX][stY];
            }
            else{
                seg[nodeX][nodeY] = seg[2*nodeX + 1][nodeY] + seg[2*nodeX+2][nodeY];
            }
        }
        else{
            int mid =( stY + enY )/2;
            buildX(matrix, nodeX, stX, enX, 2*nodeY + 1, stY, mid);
            buildX(matrix, nodeX, stX, enX, 2*nodeY + 2, mid + 1, enY);

            seg[nodeX][nodeY] = seg[nodeX][2*nodeY + 1] + seg[nodeX][2*nodeY + 2];
        }
    }


    NumMatrix(vector<vector<int>>& matrix) {
         n = matrix.size();
         m = matrix[0].size();
        seg.assign(4*n, vector<int>(4*m));
        buildY(matrix, 0, 0, n-1);
        //for this first build x then build y
    }

    int queryY(int nodeX, int nodeY, int stY, int enY, int y1, int y2){
        if(stY>=y1 && enY<=y2){
            return seg[nodeX][nodeY];
        }
        if(enY < y1 || stY > y2){
            return 0;
        }
        int mid = (stY + enY)/2;
        return queryY(nodeX, 2*nodeY + 1, stY, mid, y1, y2) + queryY(nodeX, 2*nodeY + 2, mid + 1, enY, y1, y2);
    }

    int queryX(int nodeX, int stX, int enX, int x1, int y1, int x2, int y2){
        if(stX >= x1 && enX <= x2){
            return queryY(nodeX, 0, 0, m-1, y1, y2);
        }
        if(stX > x2 || enX < x1){
            return 0;
        }
        int mid  =( stX  + enX )/2;
        return queryX(2*nodeX + 1, stX, mid, x1, y1, x2, y2) + queryX(2*nodeX + 2, mid + 1, enX, x1, y1, x2, y2);

    }

    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return queryX(0, 0, n-1, row1, col1, row2, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */