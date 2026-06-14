class Solution {
public:
    // bool solve(string s,vector<string>& wd,int i,vector<int> &dp){
    //     if(i==s.length()) return true;
    //     if(dp[i]!=-1) return dp[i];
    //     for(auto x:wd){
    //         if(i+x.length()<=s.length() && s.substr(i,x.length())==x){
    //             if(solve(s,wd,i+x.length(),dp)) return true;
    //         }
    //     }
    //     return dp[i]=false;
    // }
    bool wordBreak(string s, vector<string>& wd) {
        int n=s.size();
        unordered_set<string> dict(wd.begin(),wd.end());
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && dict.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
        // vector<int> dp(n+1,-1);
        // return solve(s,wd,0,dp);
    }
};
