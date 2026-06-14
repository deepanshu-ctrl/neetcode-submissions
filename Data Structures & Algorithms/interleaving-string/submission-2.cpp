class Solution {
public:
    vector<vector<bool>>dp;
    bool solve(int i,int j,int k, string &s1,string &s2,string &s3,vector<vector<int>> &dp){
        if(k==s3.length()) return (i==s1.length())&&(j==s2.length());
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(i<s1.length() && s1[i]==s3[k]){
            ans=solve(i+1,j,k+1,s1,s2,s3,dp);
        }
        if(j<s2.length() && s2[j]==s3[k]){
            ans=solve(i,j+1,k+1,s1,s2,s3,dp);
        }
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length(), n=s2.length();
        if(m+n!=s3.length()) return false;
        dp=vector<vector<bool>>(m+1,vector<bool>(n+1,false));
        dp[m][n]=true;
        for(int i=m;i>=0;i--){
            for(int j=n;j>=0;j--){
                if(i<m && s1[i]==s3[i+j] && dp[i+1][j]) dp[i][j]=true;
                if(j<n && s2[j]==s3[i+j] && dp[i][j+1]) dp[i][j]=true;
            }
        }
        return dp[0][0];
        // return solve(0,0,0,s1,s2,s3,dp);
    }
};
