class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
    void solve(vector<vector<char>>& g,int i,int j){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]=='0') return;
        g[i][j]='0';
        for(int k=0;k<4;k++){
            solve(g,i+dir[k][0],j+dir[k][1]);
        }
    }
    int numIslands(vector<vector<char>>& g) {
        int r=g.size();
        int c=g[0].size();
        int island=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]=='1'){
                    solve(g,i,j);
                    island++;
                }
            }
        }
        return island;
    }
};
