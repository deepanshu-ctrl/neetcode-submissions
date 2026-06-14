class Solution {
public:
    int row,col;
    set<pair<int,int>> path;
    bool solve(vector<vector<char>>& board, string word,int r,int c,int i){
        if(i==word.length()) return true;
        if(r<0 || c<0 || r>=row || c>=col || board[r][c]!=word[i] || path.count({r,c})) return false;
        path.insert({r,c});
        bool ans=solve(board,word,r+1,c,i+1) ||
        solve(board,word,r-1,c,i+1) ||
        solve(board,word,r,c+1,i+1) ||
        solve(board,word,r,c-1,i+1);
        path.erase({r,c});
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row=board.size();
        col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(solve(board,word,i,j,0)) return true;
            }
        }
        return false;
    }
};
