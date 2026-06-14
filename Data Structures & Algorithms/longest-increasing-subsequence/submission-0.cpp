class Solution {
public:
    int solve(vector<int> &nums,int i,vector<int>&dp){
        if(dp[i]!=-1) return dp[i];
        int lis=1;
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]<nums[j]){
                lis=max(lis,1+solve(nums,j,dp));
            }
        }
        return dp[i]=lis;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(nums,i,dp));
        }
        return ans;
        // vector<int> lis(n,1);
        // for(int i=nums.size()-1;i>=0;i--){
        //     for(int j=i;j<nums.size();j++){
        //         if(nums[i]<nums[j]){
        //             lis[i]=max(lis[i],1+lis[j]);
        //         }
        //     }
        // }
        // return *max_element(lis.begin(),lis.end());

        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i-1;j>=-1;j--){
        //         int ans=dp[i+1][j+1];
        //         if(j==-1 || nums[j]<nums[i]){
        //             ans=max(ans,1+dp[i+1][i+1]);
        //         }
        //         dp[i][j+1]=ans;
        //     }
        // }
        // return dp[0][0];
    }
};
