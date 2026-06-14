class Solution {
public:
    int solve(vector<int>&nums,int i,int j,vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int lis=solve(nums,i+1,j,dp);
        if(j==-1 || nums[j]<nums[i]){
            lis=max(lis,1+solve(nums,i+1,i,dp));
        }
        return dp[i][j+1]=lis;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int nt=dp[i+1][j+1];
                int tk=0;
                if(j==-1||nums[j]<nums[i]){
                    tk=1+dp[i+1][i+1];
                }
                dp[i][j+1]=max(tk,nt);
            }
        }
        return dp[0][0];
        // return solve(nums,0,-1,dp);
    }
};
