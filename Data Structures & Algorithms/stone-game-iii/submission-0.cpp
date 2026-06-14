class Solution {
public:
    int n;
    int solve(int i,int alice,vector<int>&stoneValue,vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][alice]!=INT_MIN) return dp[i][alice];
        int ans=alice==1?INT_MIN:INT_MAX;
        int score=0;
        for(int j=i;j<min(i+3,n);j++){
            if(alice==1){
                score+=stoneValue[j];
                ans=max(solve(j+1,0,stoneValue,dp)+score,ans);
            }
            else{
                score-=stoneValue[j];
                ans=min(ans,score+solve(j+1,1,stoneValue,dp));
            }
        }
        dp[i][alice]=ans;
        return ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        vector<vector<int>> dp(n,vector<int>(2,INT_MIN));
        int ans=solve(0,1,stoneValue,dp);
        if(ans==0) return "Tie";
        return ans>0?"Alice":"Bob";
    }
};