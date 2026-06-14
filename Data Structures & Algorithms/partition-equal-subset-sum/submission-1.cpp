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
        vector<vector<int>> dp(n,vector<int>(s/2+1,-1));
        return solve(nums,0,s/2,dp);
    }
};
