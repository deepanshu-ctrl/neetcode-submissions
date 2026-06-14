class Solution {
public:
    int solve(int i, int b,vector<int> &prices,vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;
        if(dp[i][b]!=-1) return dp[i][b];
        if(b) {
            int tk=-prices[i]+solve(i+1,0,prices,dp);
            int nt=solve(i+1,1,prices,dp);
            return dp[i][b]=max(tk,nt);
        }
        else{
            int sl=prices[i]+solve(i+2,1,prices,dp);
            int kp=solve(i+1,0,prices,dp);
            return dp[i][b]=max(sl,kp);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,true,prices,dp);
    }
};
