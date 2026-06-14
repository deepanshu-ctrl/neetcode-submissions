class Solution {
public:
    int solve(vector<int> &nums,vector<int> &dp,int i,int j){
        if(i>j) return 0;
        if(dp[i]!=-1) return dp[i];
        int tk=nums[i]+solve(nums,dp,i+2,j);
        int nt=solve(nums,dp,i+1,j);
        return dp[i]=max(tk,nt);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int f1=solve(nums,dp1,0,n-2);
        int f2=solve(nums,dp2,1,n-1);
        return max(f1,f2);
    }
};
