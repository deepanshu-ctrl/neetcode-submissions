class NumMatrix {
public:
    vector<vector<int>> m;
    NumMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();

        m=vector<vector<int>>(r+1,vector<int>(c+1,0));
        for(int i=0;i<r;i++){
            int p=0;
            for(int j=0;j<c;j++){
                p+=matrix[i][j];
                int ab=m[i][j+1];
                m[i+1][j+1]=p+ab;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;col1++;row2++;col2++;
        int br=m[row2][col2];
        int a=m[row1-1][col2];
        int l=m[row2][col1-1];
        int tl=m[row1-1][col1-1];
        return br-a-l+tl;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */