class Solution {
public:
    bool solve(string s,vector<string>& wd,int i,vector<int> &dp){
        if(i==s.length()) return true;
        if(dp[i]!=-1) return dp[i];
        for(auto x:wd){
            if(i+x.length()<=s.length() && s.substr(i,x.length())==x){
                if(solve(s,wd,i+x.length(),dp)) return true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return solve(s,wd,0,dp);
    }
};
