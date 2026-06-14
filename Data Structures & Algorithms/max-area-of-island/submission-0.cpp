class Solution {
public:
    int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
    int solve(vector<vector<int>>& g,int i,int j){
        if(i<0||j<0||i>=g.size()||j>=g[0].size()||g[i][j]==0) return 0;
        g[i][j]=0;
        int ans=1;
        for(int k=0;k<4;k++){
            ans+=solve(g,i+dir[k][0],j+dir[k][1]);
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
