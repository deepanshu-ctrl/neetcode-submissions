class Solution {
public:
    int solve(vector<int> &cost,vector<int> &dp,int n){
        if(n==0||n==1) return cost[n];
        if(dp[n]!=-1) return dp[n];
        int t1=cost[n]+solve(cost,dp,n-1);
        int t2=cost[n]+solve(cost,dp,n-2);
        return dp[n]=min(t1,t2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(solve(cost,dp,n-1),solve(cost,dp,n-2));
    }
};
