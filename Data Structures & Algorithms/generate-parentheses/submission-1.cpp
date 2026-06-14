class Solution {
public:
    vector<string> ans;
    void solve(int o,int c,string &temp){
        if(o==0&&c==0){
            ans.push_back(temp);
            return;
        }
        if(o>0){
            temp.push_back('(');
            solve(o-1,c,temp);
            temp.pop_back();
        }
        if(c>o){
            temp.push_back(')');
            solve(o,c-1,temp);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        solve(n,n,temp);
        return ans;
    }
};
