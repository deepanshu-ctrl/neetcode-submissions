class Solution {
public:
    // int cnt=0;
    int solve(vector<int>&nums,int t,vector<int>&dp){
        if(t==0){
            return  1;
        }
        if(t<0) return 0;
        if(dp[t]!=-1) return dp[t];
        int cnt=0;
        for(int i=0;i<nums.size();i++)
            cnt+=solve(nums,t-nums[i],dp); 
        return dp[t]=cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int t=1;t<=target;t++){
            for(int i=0;i<nums.size();i++){
                if(t-nums[i]>=0){
                    dp[t]+=dp[t-nums[i]];
                }
            }
        }
        return dp[target];
        // return solve(nums,target,dp);
    }
};
