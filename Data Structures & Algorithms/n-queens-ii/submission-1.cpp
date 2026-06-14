class Solution {
public:
    bool safe(int r,int c,vector<string> &b){
        for(int i=r-1;i>=0;i--) if(b[i][c]=='Q') return false;
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) if(b[i][j]=='Q') return false;
        for(int i=r-1,j=c+1;i>=0&&j<b.size();i--,j++) if(b[i][j]=='Q') return false;
        return true;
    }
    void solve(int r,vector<string> &b,vector<vector<string>> &ans){
        if(r==b.size()){
            ans.push_back(b); return;
        }
        for(int c=0;c<b.size();c++){
            if(safe(r,c,b)){
                b[r][c]='Q';
                solve(r+1,b,ans);
                b[r][c]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> b(n,string(n,'.'));
        solve(0,b,ans);
        return ans.size();
    }
};