class Solution {
public:
    int solve(vector<vector<int>>& m,int i,int j,int pv,vector<vector<int>> &dp){
        if(i<0||i>=m.size()||j<0||j>=m[0].size()||m[i][j]<=pv) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        int t=1+solve(m,i-1,j,m[i][j],dp);
        int l=1+solve(m,i,j+1,m[i][j],dp);
        int r=1+solve(m,i,j-1,m[i][j],dp);
        int b=1+solve(m,i+1,j,m[i][j],dp);
        ans=max({ans,t,l,r,b});
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size(), c=matrix[0].size(),ans=0;
        vector<vector<int>> dp(r,vector<int>(c,-1));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=max(ans,solve(matrix,i,j,INT_MIN,dp));
            }
        }
        return ans;
    }
};
