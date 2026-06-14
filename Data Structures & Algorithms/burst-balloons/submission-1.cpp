class Solution {
public:
    int solve(vector<int> &v,int l,int r,vector<vector<int>> &dp){
        // if(v.size()==2) return 0;
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        dp[l][r]=0;
        for(int i=l;i<=r;i++){
            int c=v[l-1]*v[i]*v[r+1];
            c+=solve(v,l,i-1,dp)+solve(v,i+1,r,dp);
            dp[l][r]=max(dp[l][r],c);
        }
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<int>v;
        v.push_back(1);
        for(auto x:nums) v.push_back(x);
        v.push_back(1);
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return solve(v,1,nums.size(),dp);
    }
};
