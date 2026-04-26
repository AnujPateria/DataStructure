class NumMatrix {
public:

    vector<vector<int>> seg;
    vector<vector<int>> arr;
    int n, m;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        arr = matrix;
        seg.assign(4*n, vector<int> (4*m, 0));
        buildX(0, 0, n-1);
    }
    
    void buildX(int nodeX, int stX, int enX){
        if(stX == enX){
            buildY(nodeX, 0, stX, 0, enX, m-1);
        }
        else{
            int mid = (stX + enX)/2;
            buildX(2*nodeX + 1, stX, mid);
            buildX(2*nodeX + 2, mid + 1, enX);
            buildY(nodeX, 0, stX, 0, enX, m-1);
        }
       
    }
    void buildY(int nodeX, int nodeY, int stX, int stY, int enX, int enY){
        if(stY == enY){
            if(stX == enX){
                seg[nodeX][nodeY] = arr[stX][stY];
            }
            else{
                seg[nodeX][nodeY] = seg[2*nodeX + 1][nodeY] + seg[2*nodeX + 2][nodeY];
            }
        }
        else{
            int mid = (stY + enY)/2;
            buildY(nodeX, 2*nodeY + 1, stX, stY, enX, mid);
            buildY(nodeX, 2*nodeY + 2, stX, mid + 1, enX, enY);
            seg[nodeX][nodeY] = seg[nodeX][2*nodeY + 1] + seg[nodeX][2*nodeY + 2];
        }
    }
    int queryY(int nodeX, int nodeY, int st_y, int en_y,
           int stY, int enY) {

    // no overlap
    if (st_y > enY || en_y < stY) return 0;

    // complete overlap
    if (st_y >= stY && en_y <= enY)
        return seg[nodeX][nodeY];

    int mid = (st_y + en_y) / 2;

    return queryY(nodeX, 2*nodeY + 1, st_y, mid, stY, enY) +
           queryY(nodeX, 2*nodeY + 2, mid+1, en_y, stY, enY);
}

int queryX(int node, int nodeX_st, int nodeX_en,
           int stX, int enX, int stY, int enY){

    // no overlap
    if (nodeX_st > enX || nodeX_en < stX) return 0;

    // complete overlap
    if (nodeX_st >= stX && nodeX_en <= enX)
        return queryY(node, 0, 0, m-1, stY, enY);

    int mid = (nodeX_st + nodeX_en) / 2;

    return queryX(2*node + 1, nodeX_st, mid, stX, enX, stY, enY) +
           queryX(2*node + 2, mid+1, nodeX_en, stX, enX, stY, enY);
}
    



    int sumRegion(int row1, int col1, int row2, int col2) {
        return queryX(0, 0, n-1, row1, row2, col1, col2);

        // return queryX()
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */