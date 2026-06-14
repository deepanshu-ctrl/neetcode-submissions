class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j==t.length()) return 1;
        if(i==s.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=solve(s,t,i+1,j,dp);
        if(s[i]==t[j]){
            ans+=solve(s,t,i+1,j+1,dp);
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {
        if(t.size()>s.size()) return 0;
        int  m=s.size(),n=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            dp[i][n]=1;
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                dp[i][j]=dp[i+1][j];
                if(s[i]==t[j]) dp[i][j]+=dp[i+1][j+1];
            }
        }
        return dp[0][0];
        // return solve(s,t,0,0,dp);
    }
};
