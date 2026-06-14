class Solution {
public:
    // int dp[101];
    int solve(vector<int> &nums,int i,vector<int> &dp){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int tk=nums[i]+solve(nums,i-2,dp);
        int nt=solve(nums,i-1,dp);
        return dp[i]=max(tk,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,n-1,dp);
    }
};
