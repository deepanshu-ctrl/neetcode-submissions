class Solution {
public:
    int m,n;
    void solve(vector<vector<int>>& matrix,int i,int j){
        for(int x=0;x<m;x++){
            if(matrix[x][j]!=0)
            matrix[x][j]=INT_MIN;
        }
        for(int x=0;x<n;x++){
            if(matrix[i][x]!=0)
            matrix[i][x]=INT_MIN;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    solve(matrix,i,j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==INT_MIN) matrix[i][j]=0;
            }
        }
    }
};
