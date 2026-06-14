class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    void solve(vector<vector<int>>& g,int i,int j,int t){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]==0) return;
        if(g[i][j]!=1 && g[i][j]<t) return;
        g[i][j]=t;
        for(auto &d:dir){
            solve(g,i+d[0],j+d[1],t+1);
        }
    }
    int orangesRotting(vector<vector<int>>& g) {
        int r=g.size();
        int c=g[0].size();
        int ans=2;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]==2){
                    solve(g,i,j,2);
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]==1) return -1;
                ans=max(ans,g[i][j]);
            }
        }
        return ans-2;
    }
};
