class Solution {
public:
    bool solve(int i,int j,int n,int m,vector<vector<char>> &b,string w,int idx){
        if(idx==w.size()){
            return true;
        }
        if(i>=n||i<0||j>=m||j<0||b[i][j]!=w[idx]) return false;
        char ch=b[i][j];
        b[i][j]='#';
        bool l=solve(i,j-1,n,m,b,w,idx+1);
        bool r=solve(i,j+1,n,m,b,w,idx+1);
        bool t=solve(i-1,j,n,m,b,w,idx+1);
        bool d=solve(i+1,j,n,m,b,w,idx+1);
        b[i][j]=ch;
        return l||r||t||d;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=solve(i,j,n,m,board,word,0);
                if(ans) return true;
            }
        }
        return ans;
    }
};

