class Solution {
public:
    int ml=1,si=0;
    bool solve(string &s,vector<vector<int>> &dp,int i,int j){
        if(i>=j) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=false;
        if(s[i]==s[j]) ans=solve(s,dp,i+1,j-1);
        if(ans){
            int l=j-i+1;
            if(l>ml){
                si=i;
                ml=l;
            }
        }
        return dp[i][j]=ans;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                bool ans=solve(s,dp,i,j);
            }
        }
        return s.substr(si,ml);
    }
};
