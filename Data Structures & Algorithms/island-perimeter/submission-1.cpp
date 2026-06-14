class Solution {
public:
    vector<vector<int>> g;
    vector<vector<bool>> vis;
    int r,c;
    int solve(int i,int j){
        if(i<0||j<0||i>=r||j>=c||g[i][j]==0) return 1;
        if(vis[i][j]) return 0;
        vis[i][j]=true;
        return solve(i,j+1)+solve(i,j-1)+solve(i+1,j)+solve(i-1,j);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        this->g=grid;
        r=grid.size();
        c=grid[0].size();
        vis=vector<vector<bool>>(r,vector<bool>(c,false));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1) return solve(i,j);
            }
        }
        return 0;
    }
};