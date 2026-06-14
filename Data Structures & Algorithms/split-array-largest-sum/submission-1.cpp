class Solution {
public:
    vector<vector<int>> dp;
    // int solve(vector<int> &nums,int i,int m,int n){
    //     if(i==n) return m==0?0:INT_MAX;
    //     if(m==0) return INT_MAX;
    //     int ans=INT_MAX,cs=0;
    //     for(int j=i;j<=n-m;j++){
    //         cs+=nums[j];
    //         ans=min(ans,max(cs,solve(nums,j+1,m-1,n)));
    //     }
    //     return ans;
    // }
    int solve(vector<int> &nums,int i,int m,int n){
        if(i==n) return m==0?0:INT_MAX;
        if(m==0) return INT_MAX;
        if(dp[i][m]!=-1) return dp[i][m];
        int ans=INT_MAX,cs=0;
        for(int j=i;j<=n-m;j++){
            cs+=nums[j];
            ans=min(ans,max(cs,solve(nums,j+1,m-1,n)));
        }
        return dp[i][m]=ans;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        dp.assign(n,vector<int>(k+1,-1));
        return solve(nums,0,k,n);
    }
};