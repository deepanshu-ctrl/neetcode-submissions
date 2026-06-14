class Solution {
public:
    int solve(vector<int>&coins,vector<int> &dp,int am){
        if(am==0) return 0;
        if(dp[am]!=-1) return dp[am];
        int ans=1e9;
        for(auto x:coins){
            if(am-x>=0)
                ans=min(ans,1+solve(coins,dp,am-x));
        }
        return dp[am]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        // int n=coins.size();
        vector<int> dp(amount+1,1e9);
        dp[0]=0;
        for(int i=0;i<=amount;i++){
            for(auto x:coins){
                if(i-x>=0){
                    dp[i]=min(dp[i],1+dp[i-x]);
                }
            }
        }
        // int ans=solve(coins,dp,amount);
        return dp[amount]>=1e9?-1:dp[amount];
    }
};
