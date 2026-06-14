class Solution {
public:
    int solve(string &s,int i){
        if(i==s.size()) return 1;
        if(s[i]=='0') return 0;
        int ans=solve(s,i+1);
        if(i<s.size()-1){
            if(s[i]=='1' ||(s[i]=='2' && s[i+1]<'7')) ans+=solve(s,i+2);
        }
        return ans;
    }
    int numDecodings(string s) {
        return solve(s,0);
    }
};
