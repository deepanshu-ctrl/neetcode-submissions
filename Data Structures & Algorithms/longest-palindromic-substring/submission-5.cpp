class Solution {
public:
    // int si=0,ml=1;
    // bool solve(string &s,vector<vector<int>> &dp,int i,int j){
    //     if(i>=j) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=false;
    //     if(s[i]==s[j]) ans=solve(s,dp,i+1,j-1);
    //     if(ans){
    //         int l=j-i+1;
    //         if(l>ml){
    //             si=i;
    //             ml=l;
    //         }
    //     }
    //     return dp[i][j]=ans;
    // }
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int si=0,ml=1;
        // for(int i=0;i<n;i++) dp[i][i]=true;
        // for(int l=2;l<=n;l++){
        //     for(int i=0;i+l-1<n;i++){
        //         int j=i+l-1;
        //         if(s[i]==s[j]){
        //             if(l==2 || dp[i+1][j-1]){
            for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                        dp[i][j]=true;
                        if(j-i+1>ml){
                            ml=j-i+1;
                            si=i;
                        }
                    }
                }
            }
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         bool ans=solve(s,dp,i,j);
        //     }
        // }
        return s.substr(si,ml);
    }
};
