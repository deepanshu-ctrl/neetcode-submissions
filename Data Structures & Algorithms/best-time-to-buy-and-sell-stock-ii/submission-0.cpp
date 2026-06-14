class Solution {
public:
    int solve(vector<int> &p,int i,int b,vector<vector<int>> &dp){
        if(i==p.size()) return 0;
        if(dp[i][b]!=-1)return dp[i][b];
        int ans=solve(p,i+1,b,dp);
        if(b==1){
            ans=max(ans,p[i]+solve(p,i+1,0,dp));
        }
        else{
            ans=max(ans,-p[i]+solve(p,i+1,1,dp));
        }
        dp[i][b]=ans;
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};