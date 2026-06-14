class Solution {
public:
    int solve(vector<int> &coins,int i,int am,vector<vector<int>> &dp){
        if(am==0) return 1;
        if(i>=coins.size()) return 0;
        if(dp[i][am]!=-1) return dp[i][am];
        int ans=0;
        if(am>=coins[i]){
            ans=solve(coins,i+1,am,dp);
            ans+=solve(coins,i,am-coins[i],dp);
        }
        return dp[i][am]=ans;
    }
    int change(int amount, vector<int>& coins) {
        // int n=coins.size();
        sort(coins.begin(),coins.end());
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int a=0;a<=amount;a++){
                if(a>=coins[i]){
                    dp[i][a]=dp[i+1][a];
                    dp[i][a]+=dp[i][a-coins[i]];
                }
            }
        }
        return dp[0][amount];
        // return solve(coins,0,amount,dp);
    }
};
