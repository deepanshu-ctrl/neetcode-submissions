class Solution {
public:
    int solve(string &t1,string &t2,int i,int j,vector<vector<int>> &dp){
        if(i==t1.size()||j==t2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(t1[i]==t2[j]) return 1+solve(t1,t2,i+1,j+1,dp);
        return dp[i][j]=max(solve(t1,t2,i+1,j,dp),solve(t1,t2,i,j+1,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(text1[i]==text2[j]) dp[i][j]=1+dp[i+1][j+1];
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        // return solve(text1,text2,0,0,dp);
    }
};
