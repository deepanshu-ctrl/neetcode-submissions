class Solution {
public:
    int solve(vector<vector<int>> &g,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1) return g[i][j];
        if(i==m || j==n) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=g[i][j]+min(solve(g,m,n,i+1,j,dp),solve(g,m,n,i,j+1,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) dp[i][j]=grid[i][j];
                else{
                    int d=(i+1<m)?dp[i+1][j]:INT_MAX;
                    int r=(j+1<n)?dp[i][j+1]:INT_MAX;
                    dp[i][j]=grid[i][j]+min(d,r);
                }
            }
        }
        // return solve(grid,m,n,0,0,dp);
        return dp[0][0];
    }
};