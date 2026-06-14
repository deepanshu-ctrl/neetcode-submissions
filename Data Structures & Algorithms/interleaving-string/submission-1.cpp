class Solution {
public:
    vector<vector<int>>dp;
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
        dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        return solve(0,0,0,s1,s2,s3,dp);
    }
};
