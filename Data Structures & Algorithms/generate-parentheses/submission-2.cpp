class Solution {
public:
    vector<string> ans;
    void solve(int n,string temp,int bal){
        if(n==0){
            if(bal==0) ans.push_back(temp);
            return;
        }
        solve(n-1,temp+'(',bal+1);
        if(bal>0) solve(n-1,temp+')',bal-1);
    }
    vector<string> generateParenthesis(int n) {
        solve(2*n,"",0);
        return ans;
    }
};
