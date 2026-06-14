class Solution {
public:
    int solve(vector<vector<int>> &og,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i>=m || j>=n) return 0;
        if(og[i][j]==1) return 0;
        if(i==m-1&&j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=solve(og,m,n,i+1,j,dp)+solve(og,m,n,i,j+1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m=og.size();
        int n=og[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(og,m,n,0,0,dp);
    }
};