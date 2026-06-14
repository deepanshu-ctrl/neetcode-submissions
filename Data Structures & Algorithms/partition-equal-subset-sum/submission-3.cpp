class Solution {
public:
    bool solve(vector<int>&nums,int i,int s,vector<vector<int>> &dp){
        if(i==nums.size()){
            return s==0;
        }
        if(s<0) return false;
        if(dp[i][s]!=-1) return dp[i][s];
        return dp[i][s]=solve(nums,i+1,s,dp)||solve(nums,i+1,s-nums[i],dp);
    }
    bool canPartition(vector<int>& nums) {
        int s=0;
        int n=nums.size();
        for(auto x:nums) s+=x;
        if(s%2!=0) return false;
        vector<vector<bool>> dp(n+1,vector<bool>(s/2+1,false));
        int t=s/2;
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=t;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][t];
        // return solve(nums,0,s/2,dp);
    }
};
