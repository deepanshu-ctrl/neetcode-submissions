class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    // int solve(vector<vector<int>>& g,int i,int j){
    //     if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]==0) return 0;
    //     g[i][j]=0;
    //     int ans=1;
    //     for(int k=0;k<4;k++){
    //         ans+=solve(g,i+dir[k][0],j+dir[k][1]);
    //     }
    //     return ans;
    // }
    int solve(vector<vector<int>>& g,int i,int j){
        queue<pair<int,int>> q;
        g[i][j]=0;
        q.push({i,j});
        int ans=1;
        while(!q.empty()){
            auto n=q.front(); q.pop();
            int r=n.first, c=n.second;
            for(int i=0;i<4;i++){
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                if(nr>=0 && nc>=0 && nr<g.size() && nc<g[0].size() && g[nr][nc]==1){
                    q.push({nr,nc});
                    g[nr][nc]=0;
                    ans++;
                }
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& g) {
        int r=g.size(),c=g[0].size();
        int area=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]==1) area=max(area,solve(g,i,j));
            }
        }
        return area;
    }
};
