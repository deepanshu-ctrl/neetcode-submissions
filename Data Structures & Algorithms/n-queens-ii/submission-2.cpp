class Solution {
public:
    int ans=0;
    bool issafe(int r,int c,vector<string> &b){
        for(int i=r-1;i>=0;i--){
            if(b[i][c]=='Q') return false;
        }
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--){
            if(b[i][j]=='Q') return false;
        }
        for(int i=r-1,j=c+1;i>=0&&j<b.size();i--,j++){
            if(b[i][j]=='Q') return false;
        }
        return true;
    }
    void solve(vector<string>&b,int r){
        if(r==b.size()){
            ans++;
            return;
        }
        for(int c=0;c<b.size();c++){
            if(issafe(r,c,b)){
                b[r][c]='Q';
                solve(b,r+1);
                b[r][c]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> v(n,string(n,'.'));
        solve(v,0);
        return ans;
    }
};