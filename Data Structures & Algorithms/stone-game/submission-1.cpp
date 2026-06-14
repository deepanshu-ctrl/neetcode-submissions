class Solution {
public:
    int solve(vector<int> &p,int i,int n,vector<vector<int>> &dp){
        if(n<i) return 0;
        if(dp[i][n]!=-1) return dp[i][n];
        int tl=p[i]+min(solve(p,i+2,n,dp),solve(p,i+1,n-1,dp));
        int tr=p[n]+min(solve(p,i,n-2,dp),solve(p,i+1,n-1,dp));
        return dp[i][n]=max(tl,tr);
    }
    bool stoneGame(vector<int>& piles) {
        int tot=0;
        for(auto x:piles) tot+=x;
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        int as=solve(piles,0,n-1,dp);
        return as>tot-as;
    }
};