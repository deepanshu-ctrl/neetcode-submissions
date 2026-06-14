#include<bits/stdc++.h>
class Solution {
public:
    int dp[30001][2];
    int solve(vector<int> &prices,int i,bool b){
        if(i==prices.size()) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        int ans=solve(prices,i+1,b);
        if(b) ans=max(ans,prices[i]+solve(prices,i+1,false));
        else ans=max(ans,-prices[i]+solve(prices,i+1,true));
        return dp[i][b]=ans;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(prices,0,false);
    }
};