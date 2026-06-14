class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{0,-1},{-1,0}};
    // void solve(vector<vector<char>>& g,int i,int j){
    //     if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]=='0') return;
    //     g[i][j]='0';
    //     for(int k=0;k<4;k++){
    //         solve(g,i+dir[k][0],j+dir[k][1]);
    //     }
    // }
    void solve(vector<vector<char>> &g,int i,int j){
        queue<pair<int,int>>q;
        g[i][j]='0';
        q.push({i,j});
        while(!q.empty()){
            auto x=q.front(); q.pop();
            int r=x.first,c=x.second;
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                if(nr>=0&&nc>=0&&nr<g.size()&&nc<g[0].size()&&g[nr][nc]=='1'){
                    q.push({nr,nc});
                    g[nr][nc]='0';
                }
            }
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
