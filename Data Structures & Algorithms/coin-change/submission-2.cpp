class Solution {
public:
    // int solve(vector<int> &c,int am,vector<int> &dp){
    //     if(am==0) return 0;
    //     if(dp[am]!=-1) return dp[am];
    //     int ans=1e9;
    //     for(auto x:c){
    //         if(am-x>=0){
    //             ans=min(ans,1+solve(c,am-x,dp));
    //         }
    //     }
    //     return dp[am]=ans;
    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto x:coins){
                if(i-x>=0){
                    dp[i]=min(dp[i],1+dp[i-x]);
                }
            }
        }
        return (dp[amount]>=1e9)?-1:dp[amount];

        // int mc=solve(coins,amount,dp);
        // return (mc>=1e9)?-1:mc;
    }
};
