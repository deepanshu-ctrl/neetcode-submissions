class Solution {
public:
    int solve(string &s,int i,vector<int> &dp){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=solve(s,i+1,dp);
        if(i<s.size()-1){
            if(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7')) ans+=solve(s,i+2,dp);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
            dp[i]=dp[i+1];
            if(i<n-1){
                if(s[i]=='1'||(s[i]=='2'&&s[i+1]<'7'))
                    dp[i]+=dp[i+2];
            }
        }
        return dp[0];
        // return solve(s,0,dp);
    }
};
