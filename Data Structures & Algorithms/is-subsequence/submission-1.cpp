class Solution {
public:
    bool solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(i==s.size()) return true;
        if(j==t.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=solve(s,t,i+1,j+1,dp);
        return dp[i][j]=solve(s,t,i,j+1,dp);
    }
    bool isSubsequence(string s, string t) {
        int m=s.size(), n=t.size();
        vector<vector<int>> v(m,vector<int>(n,-1));
        return solve(s,t,0,0,v);
    }
};