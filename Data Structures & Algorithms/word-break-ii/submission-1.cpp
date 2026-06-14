class Solution {
public:
    vector<string> ans;
    unordered_set<string>st;
    void solve(string &s,int i,string c){
        if(i==s.size()){
            c.pop_back();
            ans.push_back(c);
            return;
        }
        string temp="";
        for(int j=i;j<s.size();j++){
            temp.push_back(s[j]);
            if(st.count(temp)) solve(s,j+1,c+temp+" ");
        }
    }
    vector<string> wordBreak(string s, vector<string>& wd) {
        for(auto x:wd) st.insert(x);
        solve(s,0,"");
        return ans;
    }
};