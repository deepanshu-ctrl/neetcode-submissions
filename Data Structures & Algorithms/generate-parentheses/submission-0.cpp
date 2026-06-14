class Solution {
public:
    bool valid(string &s){
        int o=0;
        for(auto x:s){
            o+=(x=='('?1:-1);
            if (o<0) return false;
        }
        return o==0;
    }
    void solve(string s,vector<string> &ans,int n){
        if(s.length()==2*n){
            if(valid(s))
                ans.push_back(s);
            return;
        }
        solve(s+'(',ans,n);
        solve(s+')',ans,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve("",ans,n);
        return ans;
    }
};
