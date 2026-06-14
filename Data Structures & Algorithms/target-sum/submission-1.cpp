class Solution {
public:
    int ts=0;
    int solve(vector<int> &nums,int t,int i,int s,vector<vector<int>> &dp){
        if(i==nums.size()) return s==t;
        if(dp[i][s+ts]!=-1) return dp[i][s+ts];
        return dp[i][s+ts]=solve(nums,t,i+1,s+nums[i],dp)+solve(nums,t,i+1,s-nums[i],dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // for(auto x:nums) ts+=x;
        int n=nums.size();
        vector<unordered_map<int,int>> dp(n+1);
        // vector<vector<int>>dp(n+1,vector<int>(2*ts+1,-1));
        // return solve(nums,target,0,0,dp);
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(auto &p:dp[i]){
                dp[i+1][p.first+nums[i]]+=p.second;
                dp[i+1][p.first-nums[i]]+=p.second;
            }
        }
        return dp[n][target];
    }
};
