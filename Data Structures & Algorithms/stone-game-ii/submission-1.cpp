class Solution {
public:
    int solve(vector<int>&p,int i,int m,vector<vector<int>> &dp){
        int n=p.size();
        if(i>=n) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int tot=0,ans=INT_MIN;
        for(int x=1;x<=2*m && i+x-1<n;x++){
            tot+=p[i+x-1];
            ans=max(ans,tot-solve(p,i+x,max(m,x),dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int tot=0;
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        for(auto x:piles) tot+=x;
        return (tot+solve(piles,0,1,dp))/2;
    }
};