class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> r,c;
        map<pair<int,int>,unordered_set<char>> sq;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                pair<int,int> sqk={i/3,j/3};
                if(r[i].count(board[i][j]) || c[j].count(board[i][j]) || sq[sqk].count(board[i][j])) return false;
                r[i].insert(board[i][j]);
                c[j].insert(board[i][j]);
                sq[sqk].insert(board[i][j]);
            }
        }
        return true;
    }
};
