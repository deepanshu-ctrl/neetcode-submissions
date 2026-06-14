class Solution {
public:
    int countSubstrings(string s) {
        int ans=0,n=s.size();
        // vector<vector<bool>> dp(n,vector<bool>(n,false));
        // for(int i=n-1;i>=0;i--){
        //     for(int j=i;j<n;j++){
        //         if(s[i]==s[j] && (j-i<=2||dp[i+1][j-1])){
        //             dp[i][j]=true;
        //             ans++;
        //         }
        //     }
        // }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int l=i,r=j;
                while(l<=r && s[l]==s[r]){
                    l++; r--;
                }
                if(l>=r) ans++;
            }
        }
        // for(int i=0;i<s.size();i++){
        //     int l=i,r=i;
        //     while(l>=0 && r<s.size() && s[l]==s[r]){
        //         ans++;
        //         l--; r++;
        //     }
        //     l=i,r=i+1;
        //     while(l>=0 && r<s.size() && s[l]==s[r]){
        //         ans++;
        //         l--; r++;
        //     }
        // }
        return ans;
    }
};
