class Solution {
public:
    int solve(vector<int> &cost,vector<int> &dp,int i,int n){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int t1=cost[i]+solve(cost,dp,i+1,n);
        int t2=cost[i]+solve(cost,dp,i+2,n);
        return dp[i]=min(t1,t2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(cost,dp,0,n),solve(cost,dp,1,n));
    }
};
