class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(),ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ans+=4;
                    if(i && grid[i-1][j]) ans-=2;
                    if(j && grid[i][j-1]) ans-=2;
                }
                // if(grid[i][j]==1){
                //     ans+=(i+1>=m || grid[i+1][j]==0)?1:0;
                //     ans+=(j+1>=n || grid[i][j+1]==0)?1:0;
                //     ans+=(i-1<0 || grid[i-1][j]==0)?1:0;
                //     ans+=(j-1<0 || grid[i][j-1]==0)?1:0;
                // }
            }
        }
        return ans;
    }
};