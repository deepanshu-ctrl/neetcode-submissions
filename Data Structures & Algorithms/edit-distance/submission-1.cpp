class Solution {
public:
    int solve(int i,int j,string &w1,string &w2,int m,int n,vector<vector<int>> &dp){
        if(i==m) return n-j;
        if(j==n) return m-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i]==w2[j]) return solve(i+1,j+1,w1,w2,m,n,dp);
        int ans=min(solve(i+1,j,w1,w2,m,n,dp),solve(i,j+1,w1,w2,m,n,dp));
        ans=min(ans,solve(i+1,j+1,w1,w2,m,n,dp));
        return dp[i][j]=ans+1;
    }
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,word1,word2,m,n,dp);
    }
};
